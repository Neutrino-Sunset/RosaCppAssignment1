#include <iostream>
#include "BinModel02.h"
#include "Helpers.h"
#include "OptionCollection.h"

using namespace std;


int RunDefaultScenario()
{
	BinModel binModel(100, 0.1, -0.1, 0.05);
	OptionCollection options;
	options.AddCallOption(100, 4);

	options.ComputeOptions(binModel, 3, 3);
	options.OutputOptions();
	return 0;
}

int EnterScenario()
{
	BinModel binModel;

	if (binModel.GetInputData() == 1)
	{
		PauseBeforeExit();
		return 1;
	}

	OptionCollection options;
	options.InputNumberOfOptions();
	options.InputOptions();

	int n, i;
	InputNodeSelection(n, i);

	options.ComputeOptions(binModel, n, i);
	options.OutputOptions();

	return 0;
}


int main()
{
	int result;
	//result = RunDefaultScenario();
	result = EnterScenario();

	PauseBeforeExit();
	return result;
}
