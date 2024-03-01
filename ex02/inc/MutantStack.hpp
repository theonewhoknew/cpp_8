#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
		public:

			MutantStack(void) {};
			MutantStack(MutantStack &copy) : std::stack<T>(copy) {};
			MutantStack& operator=(const MutantStack &instance) {};
			~MutantStack(void) {};

			typedef typename std::deque<T>::iterator iterator;
			iterator begin()
			{
				return this->c.begin();
			}

			iterator end()
			{
				return this->c.end();
			}
};

#endif