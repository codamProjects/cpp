
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename C = std::deque<T>>
class MutantStack : public std::stack<T, C> {
	public:
		MutantStack() : std::stack<T, C>() {}
		MutantStack(MutantStack const& other) : std::stack<T, C>(other) {}

		MutantStack& operator=(MutantStack const& other) {
			if (this != &other)
				std::stack<T, C>::operator=(other);
			return (*this);
		}
		
		~MutantStack() {};

		using iterator = typename C::iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		using const_iterator = typename C::const_iterator;
		const_iterator cbegin() const { return (this->c.cbegin()); }
		const_iterator cend() const { return (this->c.cend()); }

		using reverse_iterator = typename C::reverse_iterator;
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }

		using const_reverse_iterator = typename C::const_reverse_iterator;
		const_reverse_iterator crbegin() const { return (this->c.crbegin()); }
		const_reverse_iterator crend() const { return (this->c.crend()); }
};


#endif