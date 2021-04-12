#pragma once
#include "MnaBlock.h"
#include "SignalBlock.h"

namespace ELCT350
{
  namespace Hybrid
  {
    namespace Blocks
    {
      class VelocitySensor : public Signal::SignalBlock, public Mna::MnaBlock
      {
      public:
        enum MnaPorts : size_t
        {
          S
        };

        enum OutputSignal : size_t
        {
          Velocity
        };

        VelocitySensor();

        virtual void mnaStep(double timeStep, double time) override;
        virtual void signalStep(double timeStep, double time) override;
      };
    }
  }
}