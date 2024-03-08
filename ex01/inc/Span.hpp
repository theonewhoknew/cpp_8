#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>

class Span
{	
	private:
		std::vector<int> 	_v;
		unsigned int		_n;

	public:
		Span();
		Span(unsigned int n);
		Span(Span &copy);
		Span& operator=(const Span &instance);
		~Span();

		void 	addNumber(int n);
		void	addNumberRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		void	print();

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