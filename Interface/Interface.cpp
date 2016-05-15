#include "GUI.h"

int menuChoise(char **menu, int pointCount)
{
	int menuPoint;
	title();
	for (int i = 0; i < pointCount; i++)
		if (i == pointCount - 1)
			cout << endl << "0. " << menu[i];
		else
			cout << endl << i + 1 << ". " << menu[i];

	cout << endl << endl << "Выберите пункт: ";
	fflush(stdin);
	cin >> menuPoint;
	return menuPoint;
}

void outputFactorization(vector <pair <Polynom, long long>> multipliers)
{
	for (int i = 0; i < multipliers.size(); i++)
	{
		if (multipliers[i].first.toString().length() == 1)
			cout << multipliers[i].first;
		else
			cout << '(' << multipliers[i].first << ')';
		if (multipliers[i].second > 1)
			cout << '^' << multipliers[i].second;
		if (i != multipliers.size() - 1)
			cout << " * ";
	}
}

void title()
{
	system("cls");
	cout << "Разложение полиномов с целыми коэффициентами\n";
}