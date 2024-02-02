#include "../inc/Span.hpp"
#include <iostream>

Span::Span()
{
	_n = 0;
	_v = new std::vector<int>;
	_fill = new unsigned int(0);
}

Span::Span(unsigned int n)
{	
	_n = n;
	_v = new std::vector<int>;
	_fill = new unsigned int(0);
}

Span::Span(Span &copy)
{
	_n = copy._n;
	_fill = new unsigned int(0);
	*_fill = *copy._fill;
	_v = new std::vector<int>(*_fill);
	for (unsigned int i = 0; i < *_fill; i++)
	{
		_v[i] = copy._v[i];
	}
}

Span& Span::operator=(const Span &instance)
{
	_n = instance._n;
	delete _v;
	delete _fill;
	_fill = new unsigned int(0);
	*_fill = *instance._fill;
	_v = new std::vector<int>(*_fill);
	for (unsigned int i = 0; i < *_fill; i++)
	{
		_v[i] = instance._v[i];
	}
	return (*this);
}

Span::~Span()
{
	delete _v;
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
	if (*_fill == _n)
		throw OutOfBoundsException();
	else
	{
		_v->push_back(n);
		(*_fill)++;
	}
}

unsigned int Span::shortestSpan()
{
	unsigned int	span = 0;
	unsigned int	tmp = 0;
	int				first = 1;

	if (*_fill == 0 || *_fill == 1)
		throw NoSpanException();
	std::sort(_v->begin(), _v->end());
	for (std::vector<int>::iterator iter = _v->begin(); iter != _v->end() - 1; iter++)
	{
		tmp = std::abs(*iter - *(iter + 1));
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
	if (*_fill == 0 || *_fill == 1)
		throw NoSpanException();
	std::sort(_v->begin(), _v->end());
	return (std::abs(*_v->begin() - *(_v->end() - 1)));
}