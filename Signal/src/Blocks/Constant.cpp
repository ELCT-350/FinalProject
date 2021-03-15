#include "Blocks/Constant.h"

using namespace ELCT350::Signal::Blocks;

Constant::Constant()
        : SimulationBlock(1),
          SignalBlock(0, 1)
{
}

void Constant::signalStep(double timeStep, double time)
{
  setOutputPortValue(Output, getParameterValue(ConstantValue));
}