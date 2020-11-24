#include "IdealVoltageSourceAC.h"

using namespace ELCT350::Mna;

const double IdealVoltageSourceAC::TWO_PI = 2.0 * acos(-1);

IdealVoltageSourceAC::IdealVoltageSourceAC()
                    : SimulationBlock(2), MnaBlock(3)
{
}

void IdealVoltageSourceAC::updateMna(double timeStep, double time, bool nrIteration)
{
  if(!nrIteration)
  {
    setJacobianValue(P, I, -1);
    setJacobianValue(N, I, 1);
    setJacobianValue(I, P, 1);
    setJacobianValue(I, N, -1);

    setInterceptValue(I, getParameterValue(Voltage) * sin(TWO_PI * getParameterValue(Frequency) * time));
  }
}