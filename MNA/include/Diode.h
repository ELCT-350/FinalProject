#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    class Diode final : public MnaBlock
    {
    public:
      enum Parameters
      {
        SaturationCurrent,
        ThermalVoltage,
        IdealityFactor
      };

      enum MnaPorts
      {
        Anode,
        Cathode
      };

      Diode();

      virtual void updateMna(double timeStep, double time, bool nrIteration) override;
    };
  }
}