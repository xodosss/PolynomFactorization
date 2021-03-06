#include "PolynomZ.h"

vector <pair <Polynom, long long>> PolynomZ::algebraicFact()
{
	PolynomZ p = *this;								//�������
	vector <pair <Polynom, long long>> multipliers;	//����� ���������� 	
	vector <MegaInteger> x, y;
	bool found;

	if (p.reduceCoef() != MegaRational(1))
	{
		MegaRational t[] = { p.reduceCoef() };
		multipliers.push_back({ Polynom(t, 1), 1 });
		p = p.reduce();
	}

	do
	{
		found = 0;
		//���������� ��������� ���������� � �������� ����� p
		x = p.getCoef(0).toMegaInteger().dividers();
		y = p.getCoef(p.getDegree()).toMegaInteger().dividers();
		for (auto i = 0; i < x.size() && !found; i++)
			for (auto j = 0; j < y.size() && !found; j++)
			{
				if (y[j] > 0)
				{
					//�������� �������� �� x[i]/y[j] ������ p
					MegaRational check(x[i], y[j].toMegaNatural());
					if (p.setX(check) == MegaRational())
					{
						MegaRational ma[] = { -check, MegaRational(1) };
						Polynom tmp(ma, 2);
						tmp = tmp * MegaRational(check.getDenominator());
						//���������� tmp = (y[j]*x - x[i]) � multipliers
						if (multipliers.size() > 0)
							for (int k = multipliers.size() - 1; k >= 0; k--)
							{
								if (multipliers[k].first == tmp)
								{
									multipliers[k].second++;
									break;
								}
								else if (k == 0)
									multipliers.push_back({ tmp, 1 });
							}
						else
							multipliers.push_back({ tmp, 1 });
						p = p / tmp;
						found = 1; //���������� �������
					}
				}
			}
	} while (found);

	//���������� p � multipliers
	if (p.toString() != "1")
		if (multipliers.size() > 0)
			for (int k = multipliers.size() - 1; k >= 0; k--)
			{
				if (multipliers[k].first == p)
					multipliers[k].second++;
				else if (k == 0)
					multipliers.push_back({ p, 1 });
			}
		else
			multipliers.push_back({ p, 1 });

	return multipliers;
}