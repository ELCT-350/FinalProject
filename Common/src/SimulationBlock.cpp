#include "SimulationBlock.h"
#include <stdexcept>
#include <exception>

using namespace ELCT350::Common;
using namespace std;

SimulationBlock::SimulationBlock(size_t numberOfParameters)
{
  if(numberOfParameters == 0)
    _parameters = nullptr;

  //TODO: Set _numberOfParameters
  //      Allocate the array (call new)
  //      Initialize the array (for loop)
}

SimulationBlock::~SimulationBlock()
{
  if(_parameters)
  {
    delete[] _parameters;
  }
}

 double SimulationBlock::getParameterValue(size_t parameterIndex) const
 {
   if(parameterIndex >= _numberOfParameters)
     throw out_of_range("parameterIndex");

   return _parameters[parameterIndex];
 }