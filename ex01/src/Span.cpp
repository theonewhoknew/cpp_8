#include "../inc/Span.hpp"
#include <iostream>

Span::Span()
{
	_n = 0;
}

Span::Span(unsigned int n)
{	
	_n = n;
	_v.reserve(n);
}

Span::Span(Span &copy)
{
	_n = copy._n;
	_v = copy._v;
	for (unsigned int i = 0; i < _v.size(); i++)
	{
		_v[i] = copy._v[i];
	}
}

Span& Span::operator=(const Span &instance)
{	
	if (this != &instance)
	{
		_n = instance._n;
		_v = instance._v;
	}
	return (*this);
}

Span::~Span()
{

}

const char *Span::OutOfBoundsException::what(void) const throw()
{
	return ("Vector is already full!");
};

const char *Span::NoSpanException::what(void) const throw()
{
	return ("No span can be found!");
};

void Span::addNumber(int n)
{
	if (_v.size() == _n)
		throw OutOfBoundsException();
	else
		_v.push_back(n);
}

void Span::addNumberRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = start; it != end; it++)
	{
		addNumber(*it);
	}
}

unsigned int Span::shortestSpan()
{
	unsigned int	span = 0;
	unsigned int	tmp = 0;
	int				first = 1;

	if (_v.size() == 0 || _v.size() == 1)
		throw NoSpanException();
	std::vector<int>sorted = _v;
	std::sort(sorted.begin(), sorted.end());
	for (std::vector<int>::iterator iter = sorted.begin(); iter != sorted.end() - 1; iter++)
	{
		std::vector<int>::iterator iter_cpy = iter;
		tmp = std::abs(*iter - *(++iter_cpy));
		if (first)
		{
			span = tmp;
			first = 0;
		}
		if (tmp < span)
			span = tmp;
	}
	return (span);
}

unsigned int Span::longestSpan()
{
	if (_v.size() == 0 || _v.size() == 1)
		throw NoSpanException();
	std::vector<int>sorted = _v;
	std::sort(sorted.begin(), sorted.end());
	return (std::abs(sorted.front() - sorted.back()));
}

void		Span::print()
{
	for (std::vector<int>::iterator iter = _v.begin(); iter != _v.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}