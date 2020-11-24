#pragma once

namespace ELCT350
{
  class SimulationBlock
  {
  public:
    virtual ~SimulationBlock();

    void setParameterValue(size_t index, double value);
    double getParameterValue(size_t index);
  protected:
    SimulationBlock(size_t numParameters);
  private:      
    const size_t _numParameters;
    double* _parameters;

    static void initializeArray(size_t arraySize, double array[]);
  };
}