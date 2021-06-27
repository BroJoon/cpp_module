#include "Convert.hpp"

Convert *parse_str(std::string str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return new Convert(str[0]);
	else if (str == "nanf" || str == "inff" || str =="+inff" || str == "-inff")
	{
		Convert *result = new Convert(static_cast<float>(atof(str.c_str())));
		result->setFlag(T_CHAR, IMPOSSIBLE);
		result->setFlag(T_INT, IMPOSSIBLE);
		return result;
	}
	else if (str == "nan" || str == "inf" || str =="+inf" || str == "-inf")
	{
		Convert *result = new Convert(atof(str.c_str()));
		result->setFlag(T_CHAR, IMPOSSIBLE);
		result->setFlag(T_INT, IMPOSSIBLE);
		return result;
	}

	std::stringstream sstmp;
	int type = T_INT;
	unsigned long cur = 0;

	if (str[0] == '+' || str[0] == '-')
		sstmp << str[cur++];
	while (cur < str.length())
	{
		if (str[cur] == '.')
		{
			if (type == T_DOUBLE)
				return new Convert();
			type = T_DOUBLE;
		}
		else if (str[cur] == 'e')
		{
			if (cur == str.length() - 1 ||
				(str[cur + 1] != '+' && str[cur + 1] != '-' && !std::isdigit(str[cur + 1])))
				return new Convert();
			type = T_DOUBLE;
			sstmp << str[cur++];
		}
		else if (!std::isdigit(str[cur]))
		{
			if (cur != str.length() - 1 || str[cur] != 'f')
				return new Convert();
			type = T_FLOAT;
			break;
		}
		sstmp << str[cur++];
	}
	switch (type)
	{
		case T_FLOAT:
			float f;
			sstmp >> f;
			return new Convert(f);
		case T_DOUBLE:
			double d;
			sstmp >> d;
			return new Convert(d);
		default:
			long long checkOver;
			sstmp >> checkOver;
			if (sstmp.fail() ||
				checkOver < static_cast<long long>(INT_MIN) ||
				static_cast<long long>(INT_MAX) < checkOver)
				return new Convert();
			return new Convert(static_cast<int>(checkOver));
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong argu!!" << std::endl;
		return 1;
	}
	Convert *result = parse_str(argv[1]);
	if (result->getType() == T_FLOAT)
	{
		if (!(result->isFloat()) ||
			result->getF() < static_cast<float>(INT_MIN) ||
			static_cast<float>(INT_MAX) < result->getF())
			result->setFlag(T_INT, IMPOSSIBLE);
	}
	else if (result->getType() == T_DOUBLE)
	{
		if (!(result->isDouble()) ||
			result->getD() < static_cast<double>(INT_MIN) ||
			static_cast<double>(INT_MAX) < result->getD())
			result->setFlag(T_INT, IMPOSSIBLE);
	}
	if (result->getFlag(T_INT) == IMPOSSIBLE || result->getI() < 0 || result->getI() > 127)
		result->setFlag(T_CHAR, IMPOSSIBLE);
	else if (!std::isprint(result->getC()))
		result->setFlag(T_CHAR, NON_DISPLAYABLE);
	std::cout << *result;
	delete result;
	return 0;
}