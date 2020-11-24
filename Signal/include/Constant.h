#pragma once
#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    class Constant final : public SignalBlock
    {
    public:
      enum OutputPorts : unsigned short
      {
        Output
      };

      enum Parameters : unsigned short
      {
        ConstantValue
      };

      Constant();

      virtual void updateSignal(double timeStep, double time) override;
    };
  }
}