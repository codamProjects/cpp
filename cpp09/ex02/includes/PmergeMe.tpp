
#include "PmergeMe.hpp"
#include <chrono>
#include <limits>

template <template <typename> typename C>
PmergeMe<C>::PmergeMe() : _duration(0) {}

template <template <typename> typename C>
PmergeMe<C>::~PmergeMe() {}

template <template <typename> typename C>
void	PmergeMe<C>::sortC(int const& c, char **str) {
	auto start = std::chrono::high_resolution_clock::now();
	if constexpr (std::is_same_v<C<int>, std::vector<int>>)
		this->_original.reserve(c - 1);
	for (int i = 1; i < c; i++)
		addToContainer(str[i], this->_original);
	C<std::pair<int, int>> pairs;
	if constexpr (std::is_same_v<C<std::pair<int, int>>, std::vector<std::pair<int, int>>>)
		pairs.reserve((this->_original.size() + 1) / 2);
	pairUp(this->_original, pairs);
	C<int> upper, lower;
	if constexpr (std::is_same_v<C<int>, std::vector<int>>)
		lower.reserve(c - pairs.size() - 1);
	for (std::pair<int, int> token : pairs)
		upper.emplace_back(token.second);
	upper = mergeInsertUpper(upper);
	createLower(this->_original, pairs, upper, lower);
	this->_sorted = insertLower(lower, upper);
	auto duration = std::chrono::high_resolution_clock::now() - start;
	this->_duration = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}

template <template <typename> typename C>
void	PmergeMe<C>::addToContainer(std::string const& token, C<int>& container) {
	size_t j;
	int num;
	try { 
		num = std::stoi(token, &j);
	} catch (const std::exception& e) { 
		throw std::invalid_argument("stoi failed, invalid input => " + token);
	}
	if (num < 0)
		throw std::invalid_argument("input contains negative int => " + token);
	if (j != token.size())
		throw std::invalid_argument("invalid int => " + token);
	container.emplace_back(num);
}

template <template <typename> typename C>
void	PmergeMe<C>::pairUp(C<int> const& single, C<std::pair<int, int>>& pairs) {
	auto it = single.begin();
	while(it != single.end()) {
		auto next_it = std::next(it);
		if (next_it != single.end()) {
			if (*it <= *next_it)
				pairs.emplace_back(std::make_pair(*it, *next_it));
			else
				pairs.emplace_back(std::make_pair(*next_it, *it));
			std::advance(it, 2);
		}
		else
			break ;
	}
}

template <template <typename> typename C>
void	PmergeMe<C>::createLower(C<int> const& og, C<std::pair<int, int>>& pairs, C<int> const& upper, C<int>& lower) {
	for (int token : upper) {
		for (auto it = pairs.begin(); it != pairs.end(); it++) {
			if (it->second == token) {
				lower.emplace_back(it->first);
				it = pairs.erase(it);
				break ;
			}
		}
	}
	if (og.size() % 2 == 1)
		lower.emplace_back(og.back());
}

template <template <typename> typename C>
void	PmergeMe<C>::recPair(C<int> const& base, C<int>& upper, C<int>& lower) {
	if constexpr (std::is_same_v<C<int>, std::vector<int>>) {
		const size_t size = base.size();
		for (size_t i = 0; i + 1 < size; i += 2) {
			if (base[i] <= base[i + 1]) {
				upper.emplace_back(base[i + 1]);
				lower.emplace_back(base[i]);
			}
			else {
				upper.emplace_back(base[i]);
				lower.emplace_back(base[i + 1]);
			}
			if (size % 2 == 1)
				lower.emplace_back(base.back());
		}
	}
	else {
		auto it = base.begin();
		while(it != base.end()) {
			auto next_it = std::next(it);
			if (next_it != base.end()) {
				if (*it <= *next_it) {
					upper.emplace_back(*next_it);
					lower.emplace_back(*it);
				}
				else {
					upper.emplace_back(*it);
					lower.emplace_back(*next_it);
				}
				std::advance(it, 2);
			}
			else {
				lower.emplace_back(*it);
				break ;
			}
		}
	}
	return ;
}

template <template <typename> typename C>
C<int>	PmergeMe<C>::mergeInsertUpper(C<int> const& base) {
	if (base.size() <= 1)
		return base;
	C<int> upper, lower, newBase;
	if constexpr (std::is_same_v<C<int>, std::vector<int>>) {
		newBase.reserve(base.size());
		upper.reserve(base.size() / 2);
		lower.reserve(base.size() / 2 + base.size() % 2);
	}
	recPair(base, upper, lower);
	newBase = mergeInsertUpper(upper);
	for (int token : lower) {
		auto it = std::lower_bound(newBase.begin(), newBase.end(), token);
		newBase.insert(it, token);
	}
	return (newBase);
}

template <template <typename> typename C>
void	PmergeMe<C>::jacobsthalSeq(size_t n, C<int>& jSeq) {
	if (n == 0)
		return ;
	jSeq.emplace_back(0);
	if (n == 1)
		return ;
	jSeq.emplace_back(1);
	size_t prev = 1;
	size_t prevprev = 0;
	while (jSeq.size() < n) {
		size_t num = prev + 2 * prevprev;
		if (num != prev && num < n)
			jSeq.emplace_back(num);
		prevprev = prev;
		while (jSeq.size() < n && prev < num) {
			prev++;
			if (prev < num)
				jSeq.emplace_back(prev);
		}
	}
	return ;
}

template <template <typename> typename C>
C<int>	PmergeMe<C>::insertLower(C<int> const& lower, C<int> const& upper) {
	C<int> result, jSeq;
	if constexpr (std::is_same_v<C<int>, std::vector<int>>) {
		result.reserve(upper.size() + lower.size());
		jSeq.reserve(lower.size());
		result = upper;
		jacobsthalSeq(lower.size(), jSeq);
		for (size_t i : jSeq) {
			if (i >= lower.size())
				break ;
			int value = lower[i];
			auto pIt = std::lower_bound(result.begin(), result.end(), value);
			result.insert(pIt, value);
		}	
	}
	else {
		result.insert(result.begin(), upper.begin(), upper.end());
		jacobsthalSeq(lower.size(), jSeq);
		auto it = jSeq.begin();
		while (it != jSeq.end()) {
			auto jIt = lower.begin();
			std::advance(jIt, *it);
			auto pIt = std::lower_bound(result.begin(), result.end(), *jIt);
			result.insert(pIt, *jIt);
			it++;
		}
	}
	return (result);
}

template <template <typename> typename C>
C<int> PmergeMe<C>::getOriginal() const { return (this->_original); }

template <template <typename> typename C>
C<int> PmergeMe<C>::getSorted() const { return (this->_sorted); }

template <template <typename> typename C>
long PmergeMe<C>::getDuration() const { return (this->_duration); }