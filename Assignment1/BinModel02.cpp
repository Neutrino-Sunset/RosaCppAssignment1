#include <iostream>
#include <cmath>
#include "BinModel02.h"
#include "Helpers.h"

using namespace std;


double BinModel::RiskNeutProb()
{
	return (R - D) / (U - D);
}

double BinModel::S(int n, int i)
{
	return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

int BinModel::GetInputData()
{
	//entering data
	cout << "Enter S0: ";
	S0 = EnterDouble(numeric_limits<double>::min(), numeric_limits<double>::max());

	cout << "Enter U:  ";
	U = EnterDouble(numeric_limits<double>::min(), numeric_limits<double>::max());

	cout << "Enter D:  ";
	D = EnterDouble(numeric_limits<double>::lowest(), 0);

	cout << "Enter R:  ";
	R = EnterDouble(0, numeric_limits<double>::max());

	cout << endl;

	//making sure that 0<S0, -1<D<U, -1<R
	if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D
		|| R <= -1.0)
	{
		cout << "Illegal data ranges" << endl;
		cout << "Terminating program" << endl;
		return 1;
	}

	//checking for arbitrage
	if (R >= U || R <= D)
	{
		cout << "Arbitrage exists" << endl;
		cout << "Terminating program" << endl;
		return 1;
	}

	cout << "Input data checked" << endl;
	cout << "There is no arbitrage" << endl << endl;

	return 0;
}

double BinModel::GetR()
{
	return R;
}

