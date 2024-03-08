#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	static const int arr[] = {1, 2, 3, 4, 5, 6};

	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//std::cout << "std::find in vec, looking for an int 3, result is " << (*std::find(v.begin(), v.end(), 3)) << std::endl;

	std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//std::cout << "std::find in list, looking for an int 3, result is " << (*std::find(l.begin(), l.end(), 3)) << std::endl;

	std::deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//std::cout << "std::find in deque, looking for an int 8, result is " << (*std::find(l.begin(), l.end(), 8)) << std::endl;

	try
	{
		std::cout << "easyfind  in vector, looking for an int 2, result is " << easyfind(v, 2) << std::endl;
		std::cout << "easyfind  in list, looking for an int 3, result is " << easyfind(l, 3) << std::endl;
		std::cout << "easyfind  in deque, looking for an int 8, result is " << easyfind(d, 8) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}