#include "InputPort.h"
#include "OutputPort.h"

using namespace ELCT350::Signal;

InputPort::InputPort()
{
	_connected = nullptr;
	_value = 0;
}

double InputPort::getValue() const
{
	return _value;
}

void InputPort::connect(const OutputPort& port)
{
	if (_connected)
		std::cout << "Input port already connected!" << std::endl;
	else
	{
		_connected = &port;
		Dependent::addDependency(port);
	}
}

void InputPort::copyValue()
{
	_value = _connected->getValue();
}