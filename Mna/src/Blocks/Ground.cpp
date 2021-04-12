#include "Blocks/Ground.h"

using namespace ELCT350::Mna::Blocks;

Ground::Ground()
        : SimulationBlock(0),
          MnaBlock(1)
{
  setReference(G);
}

void Ground::mnaStep(double timeStep, double time)
{
}