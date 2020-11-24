#include "Resistor.h"

using namespace ELCT350::Mna;

Resistor::Resistor()
        : SimulationBlock(1), MnaBlock(2)
{
}

void Resistor::updateMna(double timeStep, double time, bool nrIteration)
{
  if(!nrIteration)
  {
    double jacobianValue = 1.0 / getParameterValue(Resistance);
    setJacobianValue(P, P, jacobianValue);
    setJacobianValue(P, N, -jacobianValue);
    setJacobianValue(N, P, -jacobianValue);
    setJacobianValue(N, N, jacobianValue);
  }
}