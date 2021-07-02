#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <list>

class Span{
private:
	Span();

	unsigned int max;
	std::multiset<int> mset;

public:
	Span(unsigned int);
	Span(const Span &);
	virtual ~Span();

	Span &operator=(const Span &);

	void addNumber(int value);
	template<typename T>
	void addNumberToit(typename T::iterator begin, typename T::iterator end)
	{
		while (begin != end)
		{
			if (mset.size() >= max)
				throw Span::FullSpanException();
			mset.insert(*begin);
			begin++;
		}
	}
	unsigned long long shortestSpan() const;
	unsigned long long longestSpan() const;
	void print_element();


	class FullSpanException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotEnoughNumbersException: public std:: exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
