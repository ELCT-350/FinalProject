#include "SimulationBlock.h"
#include <exception>
#include <stdexcept>

using namespace ELCT350;
using namespace std;

SimulationBlock::SimulationBlock(size_t numParameters)
               : _numParameters(numParameters)
{
  if(_numParameters)
  {
    _parameters = new double[_numParameters];
    initializeArray(_numParameters, _parameters);
  }
  else
    _parameters = nullptr;
}

SimulationBlock::~SimulationBlock()
{
  if(_parameters)
  {
    delete[] _parameters;
  }
}

void SimulationBlock::initializeArray(size_t arraySize, double array[])
{
  if(!array)
    throw exception("Array is null");

  for(size_t index = 0; index < arraySize; ++index)
  {
    array[index] = 0.0;
  }
}

double SimulationBlock::getParameterValue(size_t index)
{
  if(index >= _numParameters)
    throw out_of_range("index is greater than size of parameters array");

  return _parameters[index];
}

void SimulationBlock::setParameterValue(size_t index, double value)
{
  if(index >= _numParameters)
    throw out_of_range("index is greater than size of parameters array");

  _parameters[index] = value;
}