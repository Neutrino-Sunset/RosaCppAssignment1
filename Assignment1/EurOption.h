#pragma once
#include "BinModel02.h"


class EurOption
{
public:
	int GetN() { return N; }
	void SetN(int N_) { N = N_; }

	virtual double Payoff(double z) = 0;

	void Compute(BinModel model, int n, int i);

	double PriceByCRR(BinModel model, int n, int i);

	void OutputData(int optionIndex);

private:
	int N; //steps to expiry
	int computedN;
	double price;
	double replicationX;
	double replicationY;

	double ComputeReplicationX(BinModel model, int n, int i);
	double ComputeReplicationY(BinModel model, int n, int i);
};

class Call : public EurOption
{
private:
	double K; //strike price
public:
	void SetK(double K_) { K = K_; }
	int GetInputData();
	double Payoff(double z);
};

class Put : public EurOption
{
private:
	double K; //strike price
public:
	void SetK(double K_) { K = K_; }
	int GetInputData();
	double Payoff(double z);
};
