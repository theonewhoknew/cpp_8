#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <exception>

class Span
{	
	private:
		std::vector<int> 	*_v;
		unsigned int		_n;
		unsigned int		*_fill;

	public:
		Span();
		Span(unsigned int n);
		Span(Span &copy);
		Span& operator=(const Span &instance);
		~Span();

		void 	addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif