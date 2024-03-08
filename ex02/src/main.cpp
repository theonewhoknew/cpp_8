#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	/*MutantStack*/

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.print();
		std::cout << "top element is: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size is: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		std::cout << "new stack test" << std::endl << std::endl;

		MutantStack<int>mstack_2(mstack);

		mstack_2.print();

		mstack.pop();
		mstack.pop();
		mstack.pop();

		std::cout << "first stack after change" << std::endl << std::endl;

		it = mstack.begin();
		ite = mstack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "second stack after change" << std::endl << std::endl;

		mstack_2.print();
	}

	{
		std::cout << std::endl;

		MutantStack<int> a;

		a.push(42);
		std::cout << "a is: ";
		a.print();

		MutantStack<int> b;

		b.push(100);
		std::cout << "b is: ";
		b.print();

		a = b;
		std::cout << "a after assigment is: ";
		a.print();

	}
	return 0;

	/*LIST*/
/* 	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "top element is: " << mstack.back() << std::endl;
	mstack.pop_front();
	std::cout << "size is: " << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	
	return 0; */
}