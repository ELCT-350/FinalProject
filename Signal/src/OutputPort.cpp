#include "OutputPort.h"
#include "InputPort.h"

using namespace ELCT350::Signal;

OutputPort::OutputPort()
{
	_value = 0;
}

double OutputPort::getValue() const
{
	return _value;
}

void OutputPort::setValue(double value)
{
	_value = value;
}

void OutputPort::addDependency(const InputPort& port)
{
	Dependent::addDependency(port);
}