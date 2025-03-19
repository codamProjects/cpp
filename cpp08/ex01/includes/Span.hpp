
#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iostream>
#include <set>

class Span {
	private:
		unsigned int _N;
		std::multiset<int> _container;
		Span();

	public:
		explicit Span(unsigned int const N);
		Span(Span const& other);
		Span& operator=(Span const& other);
		~Span();
		
		void	addNumber(int const num);
		void	fillUp(int min, int max);
		int		shortestSpan() const;
		int		longestSpan() const;

		template <typename C> void addContainer(const C& newC) {
			if (this->_container.size() >= this->_N)
				throw fullException();
			if (this->_container.size() + newC.size() > this->_N)
				throw addRequestToLargeException();		
			this->_container.insert(newC.begin(), newC.end());
		}

		std::multiset<int> const& getContainer() const;

		class fullException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class noSpanException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class addRequestToLargeException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, Span const& container);

#endif