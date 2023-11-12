#pragma once


class BinModel
{
private:
	double S0;
	double U;
	double D;
	double R;

public:
	BinModel()
	{}

	BinModel(double s0, double u, double d, double r) : S0(s0), U(u), D(d), R(r)
	{}

	//computing risk-neutral probability
	double RiskNeutProb();

	//computing the stock price at node n,i
	double S(int n, int i);

	//inputting, displaying and checking model data
	int GetInputData();

	double GetR();
};


