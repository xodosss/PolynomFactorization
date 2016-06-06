#include "MegaNatural.h"

MegaNatural::MegaNatural()
{
	nums.push_back((uchar)0);
}
MegaNatural::MegaNatural(const MegaNatural &ob)
{
	nums = deque<uchar>(ob.nums);
}
MegaNatural::MegaNatural(unsigned long long l)
{
	if (nums.size() == 0)
		nums.push_back((uchar)0);

	nums.at(0) = l % 10;
	l = l / 10;
	while (l > 0)
	{
		nums.push_back(l % 10);
		l = l / 10;
	};
}
MegaNatural::MegaNatural(string str)
{
	bool isInputCorrect = true;
	for (int i = 0; i < str.length() && isInputCorrect; i++)
	{
		uchar c = (uchar)(str[i] - '0');
		if (c > 9)
		{
			std::cout << "Error! Incorrect string in MegaNatural constructor.";
			isInputCorrect = false;
		}
		else
			nums.push_front(c);
	}
}

MegaNatural::~MegaNatural()
{
}

ostream& operator<<(std::ostream &os, MegaNatural &ob)
{
	os << ob.toString();
	return os;
}

string MegaNatural::toString()
{
	string temp;
	for (int i = 0; i < nums.size(); i++)
		temp += (char)(nums[nums.size() - 1 - i] + '0');
	return temp;
}

MegaNatural& MegaNatural::operator =(const MegaNatural &ob)
{
	if (&ob != this)
		this->nums = deque<uchar>(ob.nums);
	return *this;
}

//Описание: умножение на цифру
MegaNatural MegaNatural::mulByK(uchar k)
{
	MegaNatural res = *this;
	if (k == 0)
	{
		while (res.nums.size() > 1)
			res.nums.pop_back();
		res.nums[0] = 0;
	}
	else
	{
		uchar temp = 0;
		long long lng = res.nums.size();
		for (int i = 0; i < lng; i++)
		{
			res.nums[i] = res.nums[i] * k + temp;
			if (i == lng - 1 && res.nums[i] / 10)
				res.nums.push_back(res.nums[i] / 10);
			else
				temp = res.nums[i] / 10;
			res.nums[i] %= 10;
		}
	}
	return res;
}


//Описание: умножение на 10^k
void MegaNatural::mulByTenPowK(long long k)
{
	if (*this != 0)
		if (k < 0)
			while (k++ && *this != 0)
				if (nums.size() > 1)
					nums.pop_front();
				else
					nums[0] = 0;
		else
			while (k--)
				nums.push_front(0);
}

bool operator ==(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len1 = ob1.nums.size(), len2 = ob2.nums.size();
	bool frbile = len1 > len2;
	if (len1 >= len2)
	{
		int i = 0;
		for (; i < len2; i++)
			if (ob1.nums.at(i) != ob2.nums.at(i))
				return 0;
		for (; i < len1; i++)
			if (ob1.nums.at(i) != 0)
				return 0;
	}
	else
	{
		int i = 0;
		for (; i < len1; i++)
			if (ob1.nums.at(i) != ob2.nums.at(i))
				return 0;
		for (; i < len2; i++)
			if (ob2.nums.at(i) != 0)
				return 0;
	}

	return 1;



	return false;
}

bool operator !=(const MegaNatural &ob1, const MegaNatural &ob2)
{
	return !(ob1 == ob2);
}

bool operator <=(const MegaNatural &ob1, const MegaNatural &ob2)
{
	return ob2 >= ob1;
}

bool operator >=(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len1 = ob1.nums.size(), len2 = ob2.nums.size();
	if (len1 > len2)
		return true;
	else
		if (len1 < len2)
			return false;
		else
			for (int i = len1 - 1; i >= 0; i--)
				if (ob1.nums[i] != ob2.nums[i])
					return ob1.nums[i] > ob2.nums[i];
	return true;
}

bool operator <(const MegaNatural &ob1, const MegaNatural &ob2)
{
	return ob2 > ob1;
}

bool operator >(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len1 = ob1.nums.size(), len2 = ob2.nums.size();

	if (len1 >= len2)
	{
		int i = len1 - 1;
		for (; i >= len2; i--)
			if (ob1.nums.at(i) != 0)
				return 1;
		for (; i >= 0; i--)
			if (ob1.nums.at(i) != ob2.nums.at(i))
				return ob1.nums.at(i) >= ob2.nums.at(i);
	}
	else
	{
		int i = len2 - 1;
		for (; i >= len1; i--)
			if (ob2.nums.at(i) != 0)
				return 0;
		for (; i >= 0; i--)
			if (ob1.nums.at(i) != ob2.nums.at(i))
				return ob1.nums.at(i) >= ob2.nums.at(i);
	}

	return 0;
}

MegaNatural operator +(const MegaNatural &ob1, const MegaNatural &ob2)
{
	MegaNatural res;
	const MegaNatural* max_obj = (ob1.nums.size() >= ob2.nums.size()) ? &ob1 : &ob2;
	const MegaNatural* min_obj = (ob1.nums.size() < ob2.nums.size()) ? &ob1 : &ob2;

	res = *max_obj;
	res.nums.push_back(0);

	for (int i = 0; i < min_obj->nums.size(); i++)
	{
		res.nums[i] += min_obj->nums[i];
		if (res.nums[i] >= 10)
		{
			res.nums[i] %= 10;
			res.nums[i + 1] += 1;
		}
	}

	for (int i = min_obj->nums.size(); res.nums[i] >= 10 && i < max_obj->nums.size(); i++)
	{
		res.nums[i] %= 10;
		res.nums[i + 1] += 1;
	}

	if (res.nums[res.nums.size() - 1] == 0)
		res.nums.pop_back();

	return res;
}

MegaNatural operator -(const MegaNatural &ob1, const MegaNatural &ob2)
{
	if (ob1 < ob2)
	{
		printf("a-b (a<b) error return 0");
		return 0;
	}
	MegaNatural res;
	int i, len1, len2, a, b;

	len1 = ob1.nums.size();
	len2 = len1 > ob2.nums.size() ? ob2.nums.size() : len1;

	res.nums.pop_back();

	b = 0;
	for (i = 0; i < len2; i++)
	{
		a = ob1.nums.at(i) - (int)ob2.nums.at(i) - b;
		if (a < 0)
		{
			b = 1;
			a = a + 10;
		}
		else
			b = 0;

		res.nums.push_back(a);
	}
	for (; i < len1; i++)
	{
		a = ob1.nums.at(i) - b;
		if (a < 0)
		{
			b = 1;
			a = a + 10;
		}
		else
			b = 0;

		res.nums.push_back(a);
	}

	while (res.nums.size() != 1 && res.nums[res.nums.size() - 1] == 0)
		res.nums.pop_back();

	return res;
}

MegaNatural operator /(const MegaNatural &aa, const MegaNatural &b)
{
	MegaNatural a(aa);
	MegaNatural tmp = 0;
	MegaNatural res = 0;

	if (b == 0)
	{
		printf("division by zero");
		return 0;
	}

	while (a.nums.size() > 0)
	{
		while (a.nums.size() > 0 && tmp < b)
		{
			if (tmp.nums.size() == 1 && tmp.nums[0] == 0)
				tmp.nums.pop_back();

			tmp.nums.push_front(a.nums[a.nums.size() - 1]);
			a.nums.pop_back();
			res.nums.push_front(0);
		}

		while (tmp >= b)
		{
			tmp = tmp - b;
			res.nums[0] += 1;
		}
	}

	while (res.nums.size() > 1 && res.nums[res.nums.size() - 1] == 0)
		res.nums.pop_back();

	return res;
}


MegaNatural operator %(const MegaNatural &ob1, const MegaNatural &ob2)
{
	return ob1 - ob2 * (ob1 / ob2);
}

MegaNatural operator *(const MegaNatural &ob1, const MegaNatural &ob2)
{
	MegaNatural res, _ob1 = ob1;
	int len = ob2.nums.size();

	for (int i = 0; i < len; i++)
	{
		MegaNatural temp = _ob1.mulByK(ob2.nums[i]);
		temp.mulByTenPowK(i);
		res = res + temp;
	}
	return res;
}