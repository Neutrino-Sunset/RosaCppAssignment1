#pragma once
#include <vector>
#include "EurOption.h"


class OptionCollection
{
public:

	OptionCollection():numberOfOptions_(0)
	{}

	void InputNumberOfOptions();
	void InputOptions();
	void ComputeOptions(BinModel binModel, int n, int i);
	void OutputOptions();

	void AddCall(double k, int n);
	void AddPut(double k, int n);
	int GetMaxN();

private:
	void InputCall();
	void InputPut();

	std::vector<EurOption*> options_;
	int numberOfOptions_;
};

