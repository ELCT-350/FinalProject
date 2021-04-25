#include "SignalSolver.h"
#include <vector>

using namespace ELCT350::Signal;

SignalSolver::SignalSolver(double timeStep)
{
	_timeStep = timestep;
	_time = 0;
}

void SignalSolver::connect(SignalBlock& outputBlock, size_t outputPort,
	SignalBlock& inputBlock, size_t inputPort)
{
	_blocks.insert({ &outputBlock, &inputBlock });
	inputBlock.connect(inputPort, outputBlock.getOutputPort(OutputPort));
}

void SignalSolver::step() {
	vector<SignalBlock*> Blocks;
	vector<SignalBlock*> Blocks_used;
	for (size_t i = 0; i < _blocks.size(); i++)
	{
		_blocks[i].reset();
		Blocks.push_back(&_blocks[i]);
	}
	size_t n_block = Blocks.size();
	while (!Blocks.empty())
	{
		for (size_t i = 0; i < Blocks.size(); i++)
		{
			if (Blocks[i]->areDependenciesSatisfied())
			{
				Blocks_used.push_back(Blocks[i]);
				Blocks[i]->copyValues();
				Blocks[i]->signalStep(_timeStep, _time)
			}
		}
		for (size_t i = 0; i < Blocks_used.size(); i++)
		{
			for (size_t j = 0; j < Blocks.size(); j++)
			{
				if (Blocks[j] == Blocks_used[i])
				{
					Blocks.erase(j);
				}
			}
		}
		Blocks_used.clear();
	}
	_time += _timeStep;
}

double SignalSolver::getTime() const
{
	return _time;
}