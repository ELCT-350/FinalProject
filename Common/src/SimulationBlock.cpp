#include "SimulationBlock.h"

using namespace ELCT350::Common;

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