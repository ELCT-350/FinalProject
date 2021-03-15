#pragma once

namespace ELCT350
{
  namespace Common
  {
    class SimulationBlock
    {
    public:
      SimulationBlock(size_t numberOfParameters); //Create and initialize array
      ~SimulationBlock(); //delete the array

      //Getters and setters with bounds checking
      void setParameterValue(size_t parameterIndex, double value);
      double getParameterValue(size_t parameterIndex) const;
    private:
      size_t _numberOfParameters;
      double* _parameters;
    };
  }
}