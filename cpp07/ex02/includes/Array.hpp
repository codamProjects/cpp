
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T> 
class Array {
	private:
		unsigned int _size;
		T*	_elements;
	public:
		Array();
		explicit Array(unsigned int n);
		Array(Array const& other);
		Array& operator=(Array const& other);
		~Array();

		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		unsigned int size() const;

		class OOBException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

# include "Array.tpp"

#endif