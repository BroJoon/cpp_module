#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <map>

int main(void)
{
	std::cout << "=====VECTOR=====" << std::endl;
	std::vector<int> vec;
	std::vector<int> vec2(10, 42);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::vector<int>::iterator it;

	it = easyfind(vec2, 42);

	std::cout << *easyfind(vec, 1) << std::endl;
	std::cout << ((easyfind(vec, 42)) == vec.end() ? "not found" : "found") << std::endl;
	it = easyfind(vec2, 42);
	std::cout << *it << std::endl;
	std::cout << vec.capacity() << std::endl;

	std::cout << "=====LIST=====" <<  std::endl;
	std::list<int> lst;
	std::list<int> lst2(10, 42);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::cout << *easyfind(lst, 1) << std::endl;
	std::cout << ((easyfind(lst, 3)) == lst.end() ? "not found" : "found") << std::endl;
	std::cout << *easyfind(lst, 42) << std::endl;
	
	std::cout << "=====DEQUE=====" << std::endl;
	std::deque<int> deque;
	std::deque<int> deque2(10, 42);

	deque.push_back(1);
	deque.push_back(2);
	deque.push_back(3);
	deque.push_front(43);

	std::cout << *easyfind(deque, 1) << std::endl;
	std::cout << ((easyfind(deque, 4) == deque.end()) ? "not found" : "found") << std:: endl;
	std::cout << ((easyfind(deque2, 43) == deque2.end()) ? "not found" : "found") << std:: endl;

	std::cout << "=====SET=====" << std::endl;
	std::set<int> myset;
	myset.insert(10);
	myset.insert(20);
	myset.insert(30);
	myset.insert(10);

	std::cout << *easyfind(myset, 30) << std::endl;
	std::cout << ((easyfind(myset, 10)) == myset.end() ? "not found" : "found") << std::endl;
	return 0;
}