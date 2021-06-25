#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> test(10);
	try{
		std::cout << test.size() << std::endl;
		for(unsigned int i = 0;i < test.size();i++)
		{
			test[i] = i + 1;
			std::cout << (test)[i] << " ";
		}
		std::cout << std::endl;
		Array<int> test2;
		test2 = test;
		for(unsigned int i = 0;i < test2.size();i++)
			std::cout << test2[i] << " ";
		
		std::cout << std::endl << test2[3]<< std::endl;
		std::cout << test2[10] << std::endl;

	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}