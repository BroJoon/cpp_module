#ifndef Array_hpp
#define Array_hpp

#include <exception>

template <typename T>
class Array
{
private:
	unsigned int _size;
	T* array;
public:
	Array()
	{
		array = new T[0];
		_size = 0;
	}

	Array(unsigned int n)
	{
		_size = n;
		array = new T[n];
	}
	Array(const Array& other)
	{
		array = new T[other.size()];
		_size = other.size();
		for (unsigned int i = 0;i < _size;i++)
			array[i] = other.array[i];
	}
	virtual ~Array()
	{
		delete[] array;
	}

	Array &operator=(const Array& other)
	{
		if (this != &other)
		{	
			delete[] array;
			array = new T[other.size()];
			_size = other.size();
			for (unsigned int i = 0;i < _size;i++)
				array[i] = other.array[i];
		}
		return *this;
	}

 	T &operator[](unsigned int idx) const
	{
		if (idx >= _size)
			throw ArrayOutOfIndexException();
		return array[idx];
	}
	
	unsigned int size() const
	{
		return _size;
	}
	class ArrayOutOfIndexException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Error: Array: Out of index";
		}
	};
};

#endif