#include <iostream>
#include <vector>
#include <cmath>
#include "EurOption.h"

using namespace std;


double EurOption::PriceByCRR(BinModel model, int n, int i)
{
	double q = model.RiskNeutProb();

	// This isn't valid C++ it's a non-standard non-portable g++ extension which should
	// never be used, especially in commercial code.
	//double Price[N+1];
	vector<double> price(N + 1);

	for (int iIndex = 0; iIndex <= N; ++iIndex)
	{
		price[iIndex] = Payoff(model.S(N, iIndex));
	}

	if (n == N)
	{
		return price[i];
	}

	for (int nIndex = N - 1; nIndex >= 0; --nIndex)
	{
		for (int iIndex = 0; iIndex <= nIndex; ++iIndex)
		{
			price[iIndex] = (q * price[iIndex + 1] + (1 - q) * price[iIndex])
				/ (1 + model.GetR());

			if (nIndex == n && iIndex == i)
			{
				return price[iIndex];
			}
		}
	}
	return price[0];
}

void EurOption::Compute(BinModel model, int n, int i)
{
	computedN = n;
	price = PriceByCRR(model, n, i);

	if (computedN < N)
	{
		replicationX = ComputeReplicationX(model, n, i);
		replicationY = ComputeReplicationY(model, n, i);
	}
}

void EurOption::OutputData(int optionIndex)
{
	//cout << "Option " << optionIndex << " price is " << price << "; replicating strategy: x = " << replicationX
	//	<< ", y = " << replicationY << endl;
	cout << "Option " << optionIndex << " price is " << price;
	
	if (computedN < N)
	{
		cout << "; replicating strategy: x = " << replicationX << ", y = " << replicationY << endl;
	}
	else
	{
		cout << endl;
	}
}

double EurOption::ComputeReplicationX(BinModel model, int n, int i)
{
	if (n >= N || i >= N)
	{
		return 0;
	}

	++n;
	double optionPrice1 = PriceByCRR(model, n, i + 1);
	double optionPrice2 = PriceByCRR(model, n, i);
	double spot1 = model.S(n, i + 1);
	double spot2 = model.S(n, i);

	return (optionPrice1-optionPrice2)/(spot1 - spot2);
}

double EurOption::ComputeReplicationY(BinModel model, int n, int i)
{
	if (n >= N || i >= N)
	{
		return 0;
	}

	double spot = model.S(n, i);
	return price-replicationX*spot;
}


int Call::GetInputData()
{
	cout << "Enter call option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter strike price K:    "; cin >> K;
	cout << endl;
	return 0;
}

double Call::Payoff(double z)
{
	if (z > K) return z - K;
	return 0.0;
}

int Put::GetInputData()
{
	cout << "Enter put option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter strike price K:    "; cin >> K;
	cout << endl;
	return 0;
}

double Put::Payoff(double z)
{
	if (z < K) return K - z;
	return 0.0;
}
