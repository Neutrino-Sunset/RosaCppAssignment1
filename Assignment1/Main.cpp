#include <iostream>
#include "BinModel02.h"
#include "Helpers.h"
#include "OptionCollection.h"

using namespace std;


void RunScenario(string callOrPut, double s0, double u, double d, double r,
	int n, double k, int node_n, int node_i)
{
	BinModel binModel(s0, u, d, r);
	OptionCollection options;

	if (callOrPut == "call")
	{
		options.AddCall(k, n);
	}
	else if (callOrPut == "put")
	{
		options.AddPut(k, n);
	}
	else
	{
		return;
	}

	options.ComputeOptions(binModel, node_n, node_i);
	options.OutputOptions();
}

int EnterScenario()
{
	BinModel binModel;

	if (binModel.GetInputData() == 1)
	{
		return 1;
	}

	OptionCollection options;
	options.InputNumberOfOptions();
	options.InputOptions();

	int n, i;
	InputNodeSelection(n, i, options.GetMaxN());

	options.ComputeOptions(binModel, n, i);
	options.OutputOptions();

	return 0;
}


int main()
{
	int result = 0;

	do
	{
		//RunScenario("call", 100, 0.1, -0.1, 0.05, 4, 100, 3, 2);
		/*RunScenario("put", 100, 0.1, -0.1, 0.05, 4, 90, 3, 0);
		RunScenario("put", 100, 0.1, -0.1, 0.05, 4, 90, 3, 1);
		RunScenario("put", 100, 0.1, -0.1, 0.05, 4, 90, 3, 2);
		RunScenario("put", 100, 0.1, -0.1, 0.05, 4, 90, 3, 3);*/

		//RunScenario("call", 100, 0.1, -0.1, 0.05, 4, 100, 6, 2);
		result = EnterScenario();
	} while (RunAgainOrExit());

	return result;
}
