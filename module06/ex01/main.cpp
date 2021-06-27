#include <cstdlib>
#include <iostream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

char getRandomChar()
{
	std::string randomChar = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	return randomChar[rand() % randomChar.length()];
}

void *serialize(void)
{
	char *ptr = new char[20];
	for (int i = 0;i < 8;i++)
	{
		ptr[i] = getRandomChar();
		ptr[12 + i] = getRandomChar();
	}
	*reinterpret_cast<int*>(ptr + 8) = rand() % 100000;
	return static_cast<void*>(ptr);
}

Data *deserialize(void *raw)
{
	Data *data = new Data;
	data->s1 = std::string(static_cast<char*>(raw), 8);
	data->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	data->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	return data;
}

int main()
{
	srand(time(NULL));
	void *raw = serialize();
	Data* data = deserialize(raw);
	std::cout << "Deserialized s1 : " << data->s1 << " / n : "<< data->n << " / s2 : " << data->s2 << std::endl;
	delete[] static_cast<char*>(raw);
	delete data;
	return 0;
}