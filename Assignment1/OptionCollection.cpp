#include <iostream>
#include <string>
#include "OptionCollection.h"
#include "Helpers.h"

using namespace std;

void OptionCollection::InputNumberOfOptions()
{
	cout << "Enter the number of options to consider for your strategy:\nM = ";
	// TODO: Error handling if user does not enter number.
	//cin >> numberOfOptions_;

	numberOfOptions_ = EnterInt(1, 100);

	cout << endl;
}

void OptionCollection::InputOptions()
{
	for (int i = 0; i < numberOfOptions_; )
	{
		string optionType;
		cout << (i + 1) << ". Enter option data:\n";
		cout << "Enter option type (call or put): ";
		optionType = EnterOptionType();
		if (optionType == "call")
		{
			InputCall();
		}
		else if (optionType == "put")
		{
			InputPut();
		}

		++i;
	}
}

int OptionCollection::GetMaxN()
{
	int maxN = 0;
	for (int i = 0; i < options_.size(); ++i)
	{
		int n = options_[i]->GetN();
		if (n > maxN)
		{
			maxN = n;
		}
	}
	return maxN;
}

void OptionCollection::AddCall(double k, int n)
{
	Call* call = new Call();
	call->SetK(k);
	call->SetN(n);
	options_.push_back(call);
}

void OptionCollection::AddPut(double k, int n)
{
	Put* put = new Put();
	put->SetK(k);
	put->SetN(n);
	options_.push_back(put);
}

void OptionCollection::InputCall()
{
	Call* call = new Call();
	call->GetInputData();
	options_.push_back(call);
}

void OptionCollection::InputPut()
{
	Put* put = new Put();
	put->GetInputData();
	options_.push_back(put);
}

void OptionCollection::ComputeOptions(BinModel model, int n, int i)
{
	for (int oIndex = 0; oIndex < options_.size(); ++oIndex)
	{
		EurOption* option = options_[oIndex];
		option->Compute(model, n, i);
	}
}

void OptionCollection::OutputOptions()
{
	for (int oIndex = 0; oIndex < options_.size(); ++oIndex)
	{
		EurOption* option = options_[oIndex];
		option->OutputData(oIndex + 1);
	}
	cout << "\n";
}

