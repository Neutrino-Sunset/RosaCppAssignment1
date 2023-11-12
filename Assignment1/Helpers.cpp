#include <iostream>
#include <conio.h>
#include "Helpers.h"

using namespace std;


void InputNodeSelection(int& n, int& i)
{
	cout << "Enter the node in which to make computations:\n";
	cout << "n = ";
	cin >> n;
	cout << "i = ";
	cin >> i;

	cout << "\nAT NODE (n,i)=(" << n << "," << i << "):\n";
}

void PauseBeforeExit()
{
#ifdef _DEBUG
	cout << "Press enter to continue...\n";
	_getch();
#endif
}


