#include "Convert.hpp"

Convert::Convert(void) : type(T_INVALID), _c(0), _i(0), _f(0), _d(0)
{
	for (int i = 0;i < 4;i++)
		flag[i] = IMPOSSIBLE;
}

Convert::Convert(char c) :
	type(T_CHAR),
	_c(c),
	_i(static_cast<int>(c)),
	_f(static_cast<float>(c)),
	_d(static_cast<double>(c))
{
	for (int i = 0;i < 4;i++)
		flag[i] = 0;
}

Convert::Convert(int i) :
	type(T_INT),
	_c(static_cast<char>(i)),
	_i(i),
	_f(static_cast<float>(i)),
	_d(static_cast<double>(i))
{
	for (int i = 0;i < 4;i++)
		flag[i] = 0;
}

Convert::Convert(float f) :
	type(T_FLOAT),
	_c(static_cast<char>(f)),
	_i(static_cast<int>(f)),
	_f(f),
	_d(static_cast<double>(f))
{
	for (int i = 0;i < 4;i++)
		flag[i] = 0;
}

Convert::Convert(double d) :
	type(T_DOUBLE),
	_c(static_cast<char>(d)),
	_i(static_cast<int>(d)),
	_f(static_cast<float>(d)),
	_d(d)
{
	for (int i = 0;i < 4;i++)
		flag[i] = 0;
}

Convert::Convert(const Convert &other)
{
	*this = other;
}

Convert::~Convert(void)
{

}

Convert &Convert::operator=(const Convert &other)
{
	type = other.type;
	_c = other._c;
	_i = other._i;
	_f = other._f;
	_d = other._d;

	for (int i = 0;i < 4; i++)
		flag[i] = other.flag[i];
	return *this;
}

void Convert::setFlag(int idx, int value)
{
	flag[idx] = value;
}

int Convert::getType(void) const
{
	return type;
}

int Convert::getFlag(int idx) const
{
	return flag[idx];
}

char Convert::getC(void) const
{
	return _c;
}

int Convert::getI(void) const
{
	return _i;
}

float Convert::getF(void) const
{
	return _f;
}

double Convert::getD(void) const
{
	return _d;
}

bool Convert::isFloat(void) const
{
	return !(std::isinf(_f) || std::isnan(_f));
}

bool Convert::isDouble(void) const
{
	return !(std::isinf(_d) || std::isnan(_d));
}

std::ostream &operator<<(std::ostream &ofs, const Convert &other)
{
	std::string type_name[] = {
		"char",
		"int",
		"float",
		"double"
	};
	for (int i = 0;i < 4; i++) {
		std::stringstream sstmp;
		std::string stmp;
		ofs << type_name[i] << ": ";
		switch (other.getFlag(i))
		{
			case NON_DISPLAYABLE:
				ofs << NODIS;
				break;
			case IMPOSSIBLE:
				ofs << IMPOS;
				break;
			default:
				switch (i)
				{
					case 0:
						ofs << "'" << other.getC() << "'";
						break;
					case 1:
						ofs << other.getI();
						break;
					case 2:
						sstmp << other.getF();
						stmp = sstmp.str();
						if (other.isFloat()  && stmp.find('.') == std::string::npos)
							sstmp << ".0";
						sstmp << "f";
						ofs << sstmp.str();
						break;
					default:
						sstmp << other.getD();
						stmp = sstmp.str();
						if (other.isDouble() && stmp.find('.') == std::string::npos)
							sstmp << ".0";
						ofs << sstmp.str();
				}
		}
		ofs << std::endl;
	}
	return ofs;
}