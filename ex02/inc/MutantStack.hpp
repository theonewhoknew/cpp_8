#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T>
{

	public:

		typename Container::iterator begin() 
		{
        	return this->c.begin();
    	}

   		typename Container::iterator end() 
		{
        	return this->c.end();
    	}

};

#endif