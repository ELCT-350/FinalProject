#include "SignalBlock.h"
#include <stdexcept>

using namespace ELCT350::Signal;

void SignalBlock::connect(size_t inputPortIndex, const OutputPort& outputPort)
{
	_inputPorts[inputPortIndex].connect(outputPort);
}

const OutputPort& SignalBlock::getOutputPort(size_t outputPortIndex) const
{
	return _outputPorts[outputPortIndex];
}

void SignalBlock::copyValues()
{
	for (size_t i = 0; i < _numberOfInputPorts; i++)
		_inputPorts[i].copyValue();
}

SignalBlock::SignalBlock(size_t numberOfInputPorts, size_t numberOfOutputPorts)
	: _numberOfInputPorts(numberOfInputPorts), _numberOfOutputPorts(numberOfOutputPorts)
{
	_inputPorts = new InputPort[numberOfInputPorts];
	_outputPorts = new OutputPort[numberOfOutputPorts];
}

SignalBlock::~SignalBlock()
{
	if (_inputPorts)
		delete[] _inputPorts;
	if (_outputPorts)
		delete[] _outputPorts;
}

void SignalBlock::setOutputPortValue(size_t outputPortIndex, double value)
{
	if (outputPortIndex >= _numberOfOutputPorts)
		throw std::out_of_range("outputPortIndex");
	_outputPorts[outputPortIndex].setValue(value);
}

double SignalBlock::getInputPortValue(size_t inputPortIndex) const
{
	if(inputPortIndex >= _numberOfInputPorts)
		throw std::out_of_range("inputPortIndex");
	return _inputPorts[inputPortIndex].getValue();
}

void SignalBlock::addDependency(size_t outputPortIndex, size_t inputPortIndex)
{
	if (inputPortIndex >= _numberOfInputPorts)
		throw std::out_of_range("inputPortIndex");
	if (outputPortIndex >= _numberOfOutputPorts)
		throw std::out_of_range("outputPortIndex");
	_outputPorts[outputPortIndex].addDependency(_inputPorts[inputPortIndex]);
}