#include "../inc/Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{	
	{
		try
		{
			Span a(5);
			a.addNumber(1);
			a.addNumber(10);
			a.addNumber(4);
			a.addNumber(7);
			a.addNumber(20);
			
			std::cout << a.shortestSpan() << std::endl;
			std::cout << a.longestSpan() << std::endl;

			a.print();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{	
		std::srand(std::time(NULL));
		try
		{	
			Span a(10);
			for (int i = 0; i < 10; i++)
			{	 
				int random = std::rand() % 1000;
				a.addNumber(random);
			}
			std::cout << a.shortestSpan() << std::endl;
			std::cout << a.longestSpan() << std::endl;

			Span b(100000);
			for (int i = 0; i < 100000; i++)
			{	 
				int random = std::rand() % 1000000;
				b.addNumber(random);
			}
			std::cout << b.shortestSpan() << std::endl;
			std::cout << b.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	} 
	
	{
		try
		{
			Span a(5);

			std::vector<int> v;
			v.push_back(6);
			v.push_back(3);
			v.push_back(1);
			v.push_back(9);
			v.push_back(11);
			
			a.addNumberRange(v.begin(), v.end());
			a.print();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}