#include <iostream>
#include <conio.h>
#include "Helpers.h"

using namespace std;


void InputNodeSelection(int& n, int& i, int maxN)
{
	cout << "Enter the node in which to make computations:\n";
	cout << "n = ";
	n = EnterInt(0, maxN);

	cout << "i = ";
	i = EnterInt(0, maxN);

	cout << "\nAT NODE (n,i)=(" << n << "," << i << "):\n\n";
}

int EnterInt(int min, int max)
{
	int num;
	while (!(cin >> num)
		|| num < min
		|| num > max)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input: enter a number between " << min << " and " << max << endl;
	}
	return num;
}

double EnterDouble(double min, double max)
{
	double num;
	while (!(cin >> num)
		|| num < min
		|| num > max)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input: enter a number between " << min << " and " << max << endl;
	}
	return num;
}

std::string EnterOptionType()
{
	string optionType;
	while (!(cin >> optionType)
		|| (optionType != "call" && optionType != "put"))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input: enter either 'call' or 'put'\n";
	}
	return optionType;
}

void PauseBeforeExit()
{
#ifdef _DEBUG
	cout << "Press enter to continue...\n";
	_getch();
#endif
}


