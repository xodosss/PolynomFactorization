#include "PolynomZ.h"
#include "Functions.h"
#include "GUI.h"
using namespace func;
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");

	char *m_main[] = {
		"���� ����������",
		"���������� �� �������� ���������",
		"���������� �� ������������ ���������",
		"���������� �� ��������� �� ��������� ���������",
		"�����" };
	int menu;
	Polynom pol;
	PolynomZ polZ;
	char str[80];
	bool isInp = 0;
	do
	{
		menu = menuChoise(m_main, 5);
		switch (menu)
		{
		case 1: //����
			title();
			cin.ignore();
			cin.getline(str, 79, '\n');
			pol = Polynom(str);
			if (!pol.isIntegerCoefs())
			{
				cout << endl << "�������� ����" << endl;
				system("pause");
			}
			else
			{
				polZ = PolynomZ(pol);
				isInp = 1;
			}
			break;
		case 2:
			title();
			if (isInp)
			{
				cout << endl << polZ << " = ";
				outputFactorization(polZ.algebraicFact());
				cout << endl;
			}
			else
				cout << endl << "������� �� ��� ������" << endl;
			system("pause");
			break;
		case 3:
			title();
			if (isInp)
			{
				cout << endl << polZ << " = ";
				outputFactorization(polZ.kroneckerFact());
				cout << endl;
			}
			else
				cout << endl << "������� �� ��� ������" << endl;
			system("pause");
			break;
		case 4:
			title();
			if (isInp)
			{
				cout << polZ << " = ";
				outputFactorization(polZ.squaresFreeFact());
				cout << endl;
			}
			else
				cout << endl << "������� �� ��� ������" << endl;
			system("pause");
			break;
		case 0:
			break;
		default:
			title();
			cout << endl << "��� ������ �������������� ����� ����" << endl;
			system("pause");
		}
	} while (menu);

	return 0;
}
