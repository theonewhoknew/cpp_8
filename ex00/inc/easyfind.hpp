#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int to_find);

#include "easyfind.tpp"

#endif