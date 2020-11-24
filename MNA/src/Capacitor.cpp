#include "Capacitor.h"

using namespace ELCT350::Mna;

Capacitor::Capacitor()
         : SimulationBlock(1),
           MnaBlock(2)
{
}

void Capacitor::updateMna(double timeStep, double time, bool nrIteration)
{
  if(!nrIteration)
  {
    double jacobianValue = getParameterValue(Capacitance) / timeStep;
    setJacobianValue(P, P, jacobianValue);
    setJacobianValue(P, N, -jacobianValue);
    setJacobianValue(N, P, -jacobianValue);
    setJacobianValue(N, N, jacobianValue);

    double interceptValue = jacobianValue * (getAcross(P) - getAcross(N));
    setInterceptValue(P, interceptValue);
    setInterceptValue(N, -interceptValue);
  }
}