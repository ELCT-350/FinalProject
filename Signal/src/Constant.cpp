#include "Constant.h"

using namespace ELCT350::Signal;

Constant::Constant()
        : SimulationBlock(1),
          SignalBlock(0, 1)
{
}

void Constant::updateSignal(double timeStep, double time)
{
  setOutputPortValue(Output, getParameterValue(ConstantValue));
}