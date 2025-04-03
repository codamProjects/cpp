
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <string>
# include <iostream>

template <template <typename> typename C>
class PmergeMe {
	private:
		long	_duration;
		C<int>	_original;
		C<int>	_sorted;

		PmergeMe(PmergeMe const& other) = delete;
		PmergeMe& operator=(PmergeMe const& other) = delete;
	
	public:
		PmergeMe();
		~PmergeMe();

		void	sortC(int const& c, char **str);
		void	addToContainer(std::string const& token, C<int>& container);
		void	pairUp(C<int> const& single, C<std::pair<int, int>>& pairs);
		void	createLower(C<int> const& og, C<std::pair<int, int>>& pairs, C<int> const& upper, C<int>& lower);
		void	recPair(C<int> const& base, C<int>& upper, C<int>& lower);
		C<int>	mergeInsertUpper(C<int> const& base);
		void	jacobsthalSeq(size_t n, C<int>& jSeq);
		C<int>	insertLower(C<int> const& lower, C<int> const& upper);

		C<int> 	getOriginal() const;
		C<int>	getSorted() const;
		long 	getDuration() const;
};

#include "PmergeMe.tpp"

#endif