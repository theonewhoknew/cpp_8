#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class Span
{	
	private:
		std::vector<int> v;

	public:
		Span();
		Span(unsigned int n);
		Span(Span &copy);
		Span& operator=(const Span &instance);
		~Span();

		void 	addNumber();


};

#endif