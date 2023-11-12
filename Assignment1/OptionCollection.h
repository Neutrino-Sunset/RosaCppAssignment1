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

	void AddCallOption(double k, int n);

	void ComputeOptions(BinModel binModel, int n, int i);

	void OutputOptions();

	int GetMinN();

private:
	void AddCall();
	void AddPut();

	std::vector<EurOption*> options_;
	int numberOfOptions_;
};

