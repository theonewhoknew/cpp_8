#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <exception>

template <typename T>
int	easyfind(T& container, int to_find);

class NotFound : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#include "easyfind.tpp"

#endif