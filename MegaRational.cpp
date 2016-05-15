#include "MegaRational.h"
#include "Functions.h"

using namespace func;

MegaRational::MegaRational()
{
	numerator = MegaInteger();
	denominator = MegaNatural(1);
}

MegaRational::MegaRational(const MegaInteger &a)
{
	numerator = a;
	denominator = MegaNatural(1);
}

MegaRational::MegaRational(const MegaInteger &a, const  MegaNatural &b)
{
	numerator = a;
	denominator = b;
	this->reduction();
}

MegaRational::MegaRational(const MegaRational &a)
{
	numerator = a.numerator;
	denominator = a.denominator;
	this->reduction();
}

MegaRational::MegaRational(string str)
{
	string strNumerator, strDenominator;
	bool isInputedNumerator = 0, isRepeatSlash = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] > '9' || str[i] == '/' && isRepeatSlash || str[i] == '-' && i != 0)
			throw invalid_argument("incorrect input");
		else if (str[i] == '/')
		{
			isInputedNumerator = 1;
			isRepeatSlash = 1;
		}
		else if (!isInputedNumerator)
			strNumerator += str[i];
		else
			strDenominator += str[i];
	}
	denominator = MegaNatural(strDenominator);
	if (denominator == 0)
		throw invalid_argument("incorrect input");

	numerator = MegaInteger(strNumerator);
	reduction();
}

MegaRational::~MegaRational() {}

void MegaRational::reduction()
{
	MegaNatural gcd1 = gcd(this->denominator, this->numerator.toMegaNatural());
	if (gcd1 > 1)
	{
		this->numerator = this->numerator / gcd1;
		this->denominator = this->denominator / gcd1;
	}
}
bool MegaRational::isInteger()
{
	return this->denominator == 1;
}
MegaInteger MegaRational::toMegaInteger()
{
	MegaInteger ob;
	if (this->denominator == 1)
		ob = this->numerator;
	else
		std::cout << "Error in MegaRational::toMegaInteger. Number isnt Integer" << endl;
	return ob;
}

bool operator ==(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational ob1Cpy = ob1, ob2Cpy = ob2;
	if (&ob1 == &ob2)
		return true;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	return ob1Cpy.numerator == ob2.numerator &&
		ob1.denominator == ob2.denominator;
}
bool operator !=(const MegaRational &ob1, const MegaRational &ob2)
{
	return !(ob1 == ob2);
}
bool operator <(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational ob1Cpy = ob1, ob2Cpy = ob2;
	if (&ob1 == &ob2)
		return true;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	return ob1Cpy.numerator < ob2Cpy.numerator;
}
bool operator >(const MegaRational &ob1, const MegaRational &ob2)
{
	return ob2 < ob1;
}
bool operator <=(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational ob1Cpy = ob1, ob2Cpy = ob2;
	if (&ob1 == &ob2)
		return true;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	return ob1Cpy.numerator <= ob2Cpy.numerator;
}
bool operator >=(const MegaRational &ob1, const MegaRational &ob2)
{
	return ob2 <= ob1;
}

MegaRational operator +(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational res, ob1Cpy = ob1, ob2Cpy = ob2;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	res.numerator = ob1Cpy.numerator + ob2Cpy.numerator;
	res.denominator = ob1Cpy.denominator;
	res.reduction();
	return res;
}

MegaRational operator -(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational res = ob1 + (-ob2);
	return res;
}

MegaRational operator *(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational res = MegaRational(ob1.numerator * ob2.numerator,
		ob1.denominator * ob2.denominator);
	res.reduction();
	return res;
}
MegaRational operator /(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational res;
	if (ob2.numerator == 0)
		throw(invalid_argument("R u really want to div by 0?"));

	res.numerator = ob1.numerator*ob2.denominator;
	res.denominator = (ob1.denominator*ob2.numerator).toMegaNatural();
	res.numerator = res.numerator * ((ob2.numerator > 0) ? 1 : -1);
	res.reduction();

	return res;
}
MegaRational operator -(const MegaRational &ob)
{
	MegaRational res;
	res.numerator = -ob.numerator;
	res.denominator = ob.denominator;
	return res;
}

MegaRational& MegaRational::operator =(const MegaRational &ob)
{
	if (this != &ob)
	{
		this->denominator = ob.denominator;
		this->numerator = ob.numerator;
	}
	return *this;
}

void toCommonDenominator(MegaRational &ob1, MegaRational &ob2)
{
	MegaNatural lcm1 = lcm(ob1.denominator, ob2.denominator);
	ob1.numerator = ob1.numerator * (lcm1 / ob1.denominator);
	ob2.numerator = ob2.numerator * (lcm1 / ob2.denominator);
	ob1.denominator = ob2.denominator = lcm1;
}

string MegaRational::toString()
{
	string str = numerator.toString();
	if (denominator != 1 && denominator != 0)
		str += "/" + denominator.toString();
	return str;
}

ostream& operator<<(ostream &os, MegaRational &ob)
{
	os << ob.toString();
	return os;
}

MegaNatural MegaRational::getDenominator()
{
	return MegaNatural(denominator);
}

MegaInteger MegaRational::getNumerator()
{
	return MegaInteger(numerator);
}
