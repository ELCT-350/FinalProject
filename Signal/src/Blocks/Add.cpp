#include "Blocks/Add.h"

using namespace ELCT350::Signal::Blocks;

Add::Add()
    : SimulationBlock(0),
    SignalBlock(2, 1)
{
    addDependency(Output, Input1);
    addDependency(Output, Input2);
}

void Add::signalStep(double timeStep, double time)
{
    setOutputPortValue(Output, getInputPortValue(Input1) + getInputPortValue(Input2));
}