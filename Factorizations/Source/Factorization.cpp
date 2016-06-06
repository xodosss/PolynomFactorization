#include "Factorization.h"

Factorization::Factorization()
{
}

Factorization::Factorization(vector<pair<Polynom, long long>> ob)
{
	for (int i = 0; i < ob.size(); i++)
		fact.push_back(ob[i]);
}

Factorization::~Factorization()
{
}

string Factorization::toString()
{
	string str;
	if (fact.size() != 1)
		for (int i = 0; i < fact.size(); i++)
		{
			if (fact[i].first.toString().length() == 1)
				str += fact[i].first.toString();
			else
				str += "(" + fact[i].first.toString() + ")";
			if (fact[i].second > 1)
				str += '^' + to_string(fact[i].second);
			if (i != fact.size() - 1)
				str += " * ";
		}
	else
	{
		if (fact[0].first.toString().length() == 1 || fact[0].second == 1)
			str += fact[0].first.toString();
		else
			str += '(' + fact[0].first.toString() + ')';
		if (fact[0].second > 1)
			str += '^' + to_string(fact[0].second);
	}
	cout << str;
	return str;
}

