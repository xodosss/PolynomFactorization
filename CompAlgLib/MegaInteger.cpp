#include "MegaInteger.h"

MegaInteger::MegaInteger()
{
	isNegative = false;
	num = MegaNatural();
}
MegaInteger::MegaInteger(const MegaNatural &ob)
{
	isNegative = false;
	num = ob;
}
MegaInteger::MegaInteger(const MegaInteger &ob)
{
	isNegative = ob.isNegative;
	num = MegaNatural(ob.num);
}
MegaInteger::MegaInteger(long long a)
{
	if (a < 0)
	{
		isNegative = true;
		a = -a;
	}
	else
		isNegative = false;
	num = a;
}
MegaInteger::MegaInteger(string str)
{
	if (str[0] == '-')
	{
		isNegative = true;
		str.erase(0, 1);
	}
	else
		isNegative = false;
	num = MegaNatural(str);
}

MegaInteger::~MegaInteger() {}

ostream& operator<<(ostream &os, MegaInteger &ob)
{
	os << ob.toString();
	return os;
}

string MegaInteger::toString()
{
	string str = (isNegative ? "-" : "") + num.toString();
	return str;
}

MegaInteger& MegaInteger::operator =(const MegaInteger &ob)
{
	if (ob != *this)
	{
		isNegative = ob.isNegative;
		num = ob.num;
	}
	return *this;
}

MegaInteger MegaInteger::abs() const
{
	MegaInteger ob = *this;
	ob.isNegative = false;
	return ob;
}

MegaNatural MegaInteger::toMegaNatural()
{
	MegaNatural ob = num;
	return ob;
}

bool operator ==(const MegaInteger &ob1, const MegaInteger &ob2)
{
	return (ob1.num == ob2.num && (ob1.isNegative == ob2.isNegative));
}

bool operator !=(const MegaInteger &ob1, const MegaInteger &ob2)
{
	return !(ob1 == ob2);
}

bool operator >(const MegaInteger &ob1, const MegaInteger &ob2)
{
	if (ob1.isNegative)
		if (ob2.isNegative)
			return ob1.num < ob2.num;
		else
			return false;
	else
		if (ob2.isNegative)
			return true;
		else
			return ob1.num > ob2.num;
}

bool operator <(const MegaInteger &ob1, const MegaInteger &ob2)
{
	return ob2 > ob1;
}

bool operator >=(const MegaInteger &ob1, const MegaInteger &ob2)
{
	if (ob1.isNegative)
		if (ob2.isNegative)
			return ob1.num <= ob2.num;
		else
			return false;
	else
		if (ob2.isNegative)
			return true;
		else
			return ob1.num >= ob2.num;
}

bool operator <=(const MegaInteger &ob1, const MegaInteger &ob2)
{
	return ob2 >= ob1;
}

MegaInteger operator %(const MegaInteger &ob1, const MegaInteger &ob2)
{
	MegaInteger ob;
	if (ob2 != 0)
	{
		ob.num = ob1.num % ob2.num;
		if (ob1.isNegative && ob.num != 0)
			ob.num = ob2.num - ob.num;
	}
	else
	{
		cout << "Error in %(MegaInt). Div by 0." << endl;
		ob = (MegaInteger)0;
	}
	return ob;
}

MegaInteger operator *(const MegaInteger &ob1, const MegaInteger &ob2)
{
	MegaInteger ob;
	ob.num = ob1.num * ob2.num;
	if (ob != 0)
		ob.isNegative = ob1.isNegative != ob2.isNegative;
	return ob;
}

MegaInteger operator /(const MegaInteger &ob1, const MegaInteger &ob2)
{
	MegaInteger ob;
	if (ob2 != 0)
	{
		ob.num = ob1.num / ob2.num;
		ob.isNegative = ob.num == 0 ? false : ob1.isNegative != ob2.isNegative;
	}
	else
		cout << "Error in / (MegaInt). Division by 0." << endl;
	return ob;
}

MegaInteger operator +(const MegaInteger &ob1, const MegaInteger &ob2)
{
	MegaInteger ob, _ob1 = ob1, _ob2 = ob2;
	if (ob1.isNegative == ob2.isNegative)
	{
		ob.num = _ob1.num + _ob2.num;
		ob.isNegative = _ob1.isNegative;
	}
	else if (_ob1.num > _ob2.num)
	{
		ob.num = _ob1.num - _ob2.num;
		ob.isNegative = _ob1.isNegative;
	}
	else if (_ob1.num < _ob2.num)
	{
		ob.num = _ob2.num - _ob1.num;
		ob.isNegative = _ob2.isNegative;
	}
	else
		ob = (MegaInteger)0;
	return ob;
}

MegaInteger operator -(const MegaInteger &ob1, const MegaInteger &ob2)
{
	MegaInteger ob, _ob1 = ob1, _ob2 = ob2;
	ob = _ob1 + (-_ob2);
	return ob;
}

MegaInteger operator -(const MegaInteger &ob)
{
	MegaInteger res;
	res.num = ob.num;
	res.isNegative = !ob.isNegative;
	return res;
}

vector <MegaInteger> MegaInteger::dividers()
{
	vector <MegaInteger> res;
	res.push_back(1);
	res.push_back(-1);
	MegaInteger num = *this, i = 2;
	while (i <= num / 2)
	{
		if (num % i == 0)
		{
			res.push_back(i);
			res.push_back(-i);
		}
		i = i + 1;
	}
	res.push_back(num);
	res.push_back(-num);
	return res;
}