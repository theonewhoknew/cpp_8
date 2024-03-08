#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"
# include <algorithm>
# include <iostream>

const char *NotFound::what(void) const throw()
{
	return ("Element not found.");
}

template <typename T>
int	easyfind(T& container, int to_find)
{	
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw NotFound();
	else
		return *it;
}

#endif