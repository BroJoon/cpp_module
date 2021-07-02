#include "span.hpp"

Span::Span()
{

}

Span::Span(unsigned int n) : max(n)
{

}

Span::Span(const Span &other) : max(other.max)
{
	mset.clear();
	mset = other.mset;
}

Span::~Span()
{
	mset.clear();
}

Span &Span::operator=(const Span & other)
{
	if (this != &other)
	{
		max = other.max;
		mset.clear();
		mset = other.mset;
	}
	return *this;
}

void Span::addNumber(int value)
{
	if (mset.size() >= max)
        throw Span::FullSpanException();
    mset.insert(value);
}

unsigned long long Span::shortestSpan() const
{
	if (mset.size() < 2)
        throw Span::NotEnoughNumbersException();
	std::multiset<int>::iterator first = this->mset.begin();
	std::multiset<int>::iterator next = ++(this->mset.begin());
	std::multiset<int>::iterator end = mset.end();
	unsigned long long min = std::abs(*next++ - *first++);
	while (next != end)
	{
		unsigned long long tmp = std::abs(*next - *first);
		if (tmp < min)
			min = tmp;
		first++;
		next++;
	}
	return(min);
}

unsigned long long Span::longestSpan() const
{
	if (mset.size() < 2)
        throw Span::NotEnoughNumbersException();
	return std::abs((long long)*std::max_element(mset.begin(), mset.end()) - *std::min_element(mset.begin(), mset.end()));
}

void Span::print_element()
{
	std::multiset<int>::iterator begin = mset.begin();
	std::multiset<int>::iterator end = mset.end();

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

const char* Span::FullSpanException::what() const throw()
{
	return "SpanException: Spain is already full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "SpanException: not enough numbers in Span";
}
