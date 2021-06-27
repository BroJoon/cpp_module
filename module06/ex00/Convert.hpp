#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <climits>
#include <sstream>
#include <cmath>

#define NON_DISPLAYABLE 1
#define IMPOSSIBLE 2
#define NODIS "Non displayable"
#define IMPOS "impossible"

#define T_CHAR 0
#define T_INT 1
#define T_FLOAT 2
#define T_DOUBLE 3
#define T_INVALID 4

class Convert
{
	private:
		int flag[4];
		int type;
		char _c;
		int _i;
		float _f;
		double _d;
	public:
		Convert(void);
		Convert(char c);
		Convert(int i);
		Convert(float f);
		Convert(double d);
		Convert(const Convert &other);
		~Convert(void);
		
		Convert &operator=(const Convert &other);

		void setFlag(int idx, int value);
		bool isFloat(void) const;
		bool isDouble(void) const;
	
		int getType(void) const;
		int getFlag(int idx) const;
		char getC(void) const;
		int getI(void) const;
		float getF(void) const;
		double getD(void) const;
};

std::ostream &operator<<(std::ostream &ofs, const Convert &other);

#endif