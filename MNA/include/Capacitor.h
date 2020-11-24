#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    class Capacitor final : public MnaBlock
    {
    public:
      enum Parameters
      {
        Capacitance
      };

      enum MnaPorts
      {
        P,
        N
      };

      Capacitor();

      virtual void updateMna(double timeStep, double time, bool nrIteration) override;
    };
  }
}