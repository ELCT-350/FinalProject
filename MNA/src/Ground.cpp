#include "Ground.h"

using namespace ELCT350::Mna;

Ground::Ground()
      : SimulationBlock(0), MnaBlock(1)
{
  setPortReference(G);
}

void Ground::updateMna(double timeStep, double time, bool nrIteration)
{
}