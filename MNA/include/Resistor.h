#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    class Resistor final : public MnaBlock
    {
    public:
      enum Parameters
      {
        Resistance
      };

      enum MnaPorts
      {
        P,
        N
      };

      Resistor();

      virtual void updateMna(double timeStep, double time, bool nrIteration) override;
    };
  }
}