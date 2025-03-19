
#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename A, typename F>
void iter(A* array, size_t length, F func) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
};

#endif
