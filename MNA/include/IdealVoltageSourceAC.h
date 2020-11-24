#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    class IdealVoltageSourceAC final : public MnaBlock
    {
    public:
      enum Parameters
      {
        Voltage,
        Frequency
      };

      enum MnaPorts
      {
        P,
        N,
        I
      };

      IdealVoltageSourceAC();

      virtual void updateMna(double timeStep, double time, bool nrIteration) override;
    private:
      static const double TWO_PI;
    };
  }
}