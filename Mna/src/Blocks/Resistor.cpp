#include "Blocks/Resistor.h"

using namespace ELCT350::Mna::Blocks;

Resistor::Resistor()
        : SimulationBlock(1),
          MnaBlock(2)
{
}

void Resistor::mnaStep(double timeStep, double time)
{
  double conductance = 1.0 / getParameterValue(Resistance);
  setJacobianValue(P, P, conductance);
  setJacobianValue(P, N, -conductance);
  setJacobianValue(N, P, -conductance);
  setJacobianValue(N, N, conductance);

  setInterceptValue(P, 0.0);
  setInterceptValue(N, 0.0);
}