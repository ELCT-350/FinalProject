#include "SignalBlock.h"
#include <exception>
#include <stdexcept>

using namespace ELCT350::Signal;
using namespace std;

SignalBlock::SignalBlock(size_t numInputPorts, size_t numOutputPorts)
           : _numInputPorts(numInputPorts),
             _numOutputPorts(numOutputPorts)
{
  if(_numInputPorts > 0)
  {
    _inputPorts = new SignalInputPort[_numInputPorts];    
  }
  else
    _inputPorts = nullptr;

  if(_numOutputPorts)
  {    
    _outputPorts = new SignalOutputPort[_numOutputPorts];
  }
  else
    _outputPorts = nullptr;
}

SignalBlock::~SignalBlock()
{
  if(_inputPorts != nullptr)
  {
    delete[] _inputPorts;
  }

  if(_outputPorts)
  {
    delete[] _outputPorts;
  }
}

void SignalBlock::addDependency(size_t outputPortIndex, size_t inputPortIndex)
{
  if(inputPortIndex >= _numInputPorts)
    throw out_of_range("index is greater than size of input port array");
  if(outputPortIndex >= _numOutputPorts)
    throw out_of_range("index is greater than size of output port array");

  _outputPorts[outputPortIndex].addDependency(_inputPorts[inputPortIndex]);
  Dependent::addDependency(_inputPorts[inputPortIndex]);
}

void SignalBlock::setOutputPortValue(size_t index, double value)
{
  if(index >= _numOutputPorts)
    throw out_of_range("index is greater than size of output ports array");

  _outputPorts[index].setValue(value);
}

double SignalBlock::getOutputPortValue(size_t index)
{
  if(index >= _numOutputPorts)
    throw out_of_range("index is greater than size of output ports array");

  return _outputPorts[index].getValue();
}

double SignalBlock::getInputPortValue(size_t index)
{
  if(index >= _numInputPorts)
    throw out_of_range("index is greater than size of input ports array");

  return _inputPorts[index].getValue();
}

void SignalBlock::connect(size_t inputPortIndex, const SignalBlock& outputBlock, size_t outputPortIndex)
{
  if(inputPortIndex >= _numInputPorts)
    throw out_of_range("index is greater than size of input ports array");

  if(outputPortIndex >= outputBlock._numOutputPorts)
    throw out_of_range("index is greater than size of output ports array");

  _inputPorts[inputPortIndex].connect(outputBlock._outputPorts[outputPortIndex]);
}

void SignalBlock::copyValues()
{
  for(size_t inputPort = 0; inputPort < _numInputPorts; ++inputPort)
    _inputPorts[inputPort].copyValue();
}

void SignalBlock::reset()
{
  for(size_t inputPort = 0; inputPort < _numInputPorts; ++inputPort)
  {
    _inputPorts[inputPort].reset();
  }

  for(size_t outputPort = 0; outputPort < _numOutputPorts; ++outputPort)
  {
    _outputPorts[outputPort].reset();
  }
}

bool SignalBlock::isSet() const
{
  for(size_t outputPort = 0; outputPort < _numOutputPorts; ++outputPort)
  {
    if(!_outputPorts[outputPort].isSet())
      return false;
  }

  return true;
}