#include "Blocks/Gain.h"

using namespace ELCT350::Signal::Blocks;

Gain::Gain()
    : SimulationBlock(1),
      SignalBlock(1, 1)
{
  addDependency(Output, Input);
}

void Gain::signalStep(double timeStep, double time)
{
  setOutputPortValue(Output, getInputPortValue(Input) * getParameterValue(GainValue));
}