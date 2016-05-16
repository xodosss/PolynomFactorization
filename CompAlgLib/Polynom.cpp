#include "Polynom.h"
#include "Functions.h"
using namespace func;

Polynom::Polynom()
{
	this->coefficients.push_front(MegaRational());
}

Polynom::Polynom(const Polynom &ob)
{
	coefficients = deque<MegaRational>(ob.coefficients);
}

Polynom::Polynom(const string str)
{
	int i = 0;
	while (i < str.length())
	{
		while (!isdigit(str[i]) && str[i] != 'x')
			i++;
			
		int num = 0, j = 0, sign;
		if (str[i] == 'x')
			num = (i == 0 || str[i - 1] != '-') ? 1 : -1;
		else
		{
			sign = (i == 0 || str[i - 1] != '-') ? 1 : -1;
			while (isdigit(str[i]))
			{
				num *= 10;
				num += (str[i] - '0');
				i++; j++;
			}
			num *= sign;
		}

		while (!isdigit(str[i]) && str[i] != '\0')
			i++;

		int nump = 0;
		j = 0;
		while (isdigit(str[i]))
		{
			nump *= pow(10, j);
			nump += (str[i] - '0');
			i++; j++;
		}

		if (nump > coefficients.size())
			coefficients.resize(nump + 1);
		coefficients[nump] = (MegaRational(num, 1));
	}
}

MegaNatural Polynom::getNextNum(string str, int& pos)
{
	string res = "";

	while (pos < str.size() && !isdigit(str[pos]))
		pos++;

	while (pos < str.size() && isdigit(str[pos]))
	{
		res += (str[pos]);
		pos++;
	}
	return MegaNatural(res);
}

Polynom::Polynom(const MegaRational *coeffs, long degree)
{
	for (long i = 0; i < degree; i++)
		this->coefficients.push_back(coeffs[i]);
}

Polynom::Polynom(const long *coeffs, long degree)
{
	for (long i = 0; i < degree; i++)
		this->coefficients.push_back((MegaRational)coeffs[i]);
}

Polynom::~Polynom()
{

}

long long Polynom::getDegree()
{
	if (this->coefficients.size() == 0)
		return this->coefficients.size();
	else
		return this->coefficients.size() - 1;
}

Polynom Polynom::fluxion()
{
	Polynom res = *this;
	res.coefficients.pop_front();

	for (int i = 0; i < res.coefficients.size(); i++)
		res.coefficients[i] = ((res.coefficients[i])*MegaRational(i + 1));
	return res;
}


bool operator ==(const Polynom &p1, const Polynom &p2)
{
	if (p1.coefficients.size() != p2.coefficients.size())
		return false;
	for (int i = 0; i < p1.coefficients.size(); i++)
		if (p1.coefficients[i] != p2.coefficients[i])
			return false;
	return true;
}

bool operator !=(const Polynom &p1, const Polynom &p2)
{
	return !(p1 == p2);
}

Polynom operator +(const Polynom &p1, const Polynom &p2)
{
	Polynom res, tmp;
	if (p1.coefficients.size() >= p2.coefficients.size())
		res = p1, tmp = p2;
	else
		res = p2, tmp = p1;
	for (int i = 0; i < tmp.coefficients.size(); i++)
		res.coefficients[i] = (res.coefficients[i] + tmp.coefficients[i]);
	for (int i = res.coefficients.size() - 1; i > 0 && (res.coefficients[i] == MegaRational()); i--)
		res.coefficients.pop_back();
	return res;
}

Polynom operator -(const Polynom &p1, const Polynom &p2)
{
	return p1 + (-p2);
}

Polynom operator /(const Polynom &p1, const Polynom &p2)
{
	Polynom res = Polynom(), _p1 = p1, _p2 = p2;
	res.coefficients.pop_back();
	if (_p2.coefficients.size() - 1 == 0 && _p2.coefficients[0] == MegaRational())
		throw(invalid_argument("Error, div by zero polynom\n"));

	if (_p1.coefficients.size() < _p2.coefficients.size())
		return Polynom();

	long long n = _p2.coefficients.size() - 1, k = _p1.coefficients.size() - (n + 1);
	while (k >= 0)
	{
		if (_p1.coefficients.size() - 1 < n + k)
		{
			res.coefficients.push_front(MegaRational());
		}
		else
		{
			res.coefficients.push_front((_p1.coefficients[n + k] / _p2.coefficients[n]));
			_p1 = _p1 - (_p2 * res.coefficients[0]).mulByXPowK(k);
		}
		k--;
	}
	return res;
}

Polynom operator %(const Polynom &p1, const Polynom &p2)
{
	try
	{
		return p1 - p2 * (p1 / p2);
	}
	catch (invalid_argument &exc)
	{
		throw exc;
	}
}

Polynom operator *(const Polynom &p1, const Polynom &p2)
{
	Polynom res = Polynom(), p1Cpy, p2Cpy;
	MegaRational cmp = MegaRational();
	if (p1.coefficients.size() < p2.coefficients.size())
		p1Cpy = p1, p2Cpy = p2;
	else
		p1Cpy = p2, p2Cpy = p1;

	for (long long i = p2Cpy.coefficients.size() - 1; i >= 0; i--)
	{
		//if (p2Cpy.coefficients[i] != cmp)
		res = res + (p1Cpy * p2Cpy.coefficients[i]).mulByXPowK(i);
	}
	return res;
}

Polynom operator *(const Polynom &p, const MegaRational &a)
{
	Polynom res = p;
	if (a == MegaRational())
		return Polynom();

	for (int i = 0; i < p.coefficients.size(); i++)
		res.coefficients[i] = res.coefficients[i] * a;

	return res;
}

Polynom operator /(const Polynom &p, const MegaRational &a)
{
	Polynom res = p;
	if (a == MegaRational())
		return Polynom();

	for (int i = 0; i < p.coefficients.size(); i++)
		res.coefficients[i] = res.coefficients[i] / a;

	return res;
}
Polynom operator -(const Polynom &p)
{
	return p * MegaRational(-1);
}

Polynom& Polynom::operator= (const Polynom &p)
{
	if (p != *this)
		coefficients = deque<MegaRational>(p.coefficients);
	return *this;
}

Polynom Polynom::mulByXPowK(long long k)
{
	if (*this != Polynom())
		if (k < 0)
			while (k++ && *this != Polynom())
				if (coefficients.size() > 1)
					coefficients.pop_front();
				else
					coefficients[0] = MegaRational();
		else
			while (k--)
				coefficients.push_front(MegaRational());
	return *this;
}

MegaRational Polynom::reduceCoef()
{
	MegaNatural gcd1, lcm1 = 1;
	MegaRational coefficent;

	if (*this == Polynom())
		return MegaRational();

	gcd1 = coefficients[coefficients.size() - 1].getNumerator().toMegaNatural();
	for (long long i = coefficients.size() - 2; i >= 0; i--)
		if (coefficients[i] != MegaRational())
			gcd1 = gcd(gcd1, coefficients[i].getNumerator().toMegaNatural());

	for (long long i = coefficients.size() - 1; i >= 0; i--)
		lcm1 = lcm(lcm1, coefficients[i].getDenominator());

	coefficent = MegaRational(MegaInteger(gcd1), lcm1);

	return coefficent;
}

string Polynom::toString()
{
	string str;
	if (coefficients.size() == 1 && coefficients[0] == MegaRational())
		return "0";

	for (auto i = getDegree(); i >= 0; i--)
	{
		if (coefficients[i] != MegaRational())
		{
			if (coefficients[i].getNumerator() < 0)
				str += "-";
			else if (i != getDegree())
				str += "+";

			if (coefficients[i].getDenominator() != 1)
				str += '(';
			if (coefficients[i].getNumerator() != 1 && coefficients[i].getNumerator() != -1 || i == 0)
				str += coefficients[i].getNumerator().abs().toString();
			if (coefficients[i].getDenominator() != 1)
				str += '/' + coefficients[i].getDenominator().toString() + ')';
			if (i > 0)
			{
				str += 'x';
				if (i > 1)
				{
					str += '^';
					str += std::to_string(i);
				}
			}
		}
		else
			if (i == 0 && str == "")
				str = "0";
	}
	return str;
}

ostream& operator<<(std::ostream &os, Polynom &ob)
{
	os << ob.toString();
	return os;
}

MegaRational pow(MegaRational num, int k)
{
	MegaRational res = MegaRational(1);
	while (k--)
		res = res * num;

	return res;
}


MegaRational Polynom::setX(MegaRational x)
{
	MegaRational res = MegaRational();
	for (int i = this->getDegree(); i >= 0; i--)
		res = res + this->coefficients[i] * pow(x, i);
	return res;
}


Polynom Polynom::reduce()
{
	return *this / reduceCoef();
}

MegaRational Polynom::getCoef(const long &n)
{
	return coefficients[n];
}

bool Polynom::isIntegerCoefs()
{
	for (int i = getDegree(); i >= 0; i--)
		if (coefficients[i].getDenominator() != 1)
			return 0;
	return 1;
}