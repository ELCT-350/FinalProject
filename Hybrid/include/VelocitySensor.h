#pragma once
#include "SignalBlock.h"
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Hybrid
  {
    class VelocitySensor : public Signal::SignalBlock, public Mna::MnaBlock
    {
    public:
      #pragma region Ports
      enum SignalOutputPorts : unsigned short
      {
        Velocity
      };

      enum MnaPorts : unsigned short
      {
        Shaft
      };
      #pragma endregion

      #pragma region Constructors
      VelocitySensor();
      #pragma endregion

      #pragma region SignalBlock
      void updateSignal(double timeStep, double time) override;
      #pragma endregion

      #pragma region MnaBlock
      void updateMna(double timeStep, double time, bool nrIterate) override;
      #pragma endregion
    };
  }
}