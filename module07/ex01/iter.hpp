#ifndef iter_hpp
#define iter_hpp

template<typename T>
void iter(T* array, unsigned int size, void (*f)(T const &))
{
	for (unsigned int i = 0;i < size;i++)
		f(array[i]);
}

#endif