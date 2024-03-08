#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
		public:

			MutantStack(void) {};
			MutantStack(MutantStack &copy) : std::stack<T>(copy) {};
			MutantStack& operator=(const MutantStack &instance) {this->c = instance.c; return *this;};
			~MutantStack(void) {};

			void print() {MutantStack<T>::iterator it = this->begin();
					MutantStack<T>::iterator ite = this->end();

					while (it != ite)
					{
						std::cout << *it << std::endl;
						++it;
					}};

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