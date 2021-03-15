#pragma once
#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class Gain : public SignalBlock
      {
      public:
        enum Parameters : size_t
        {
          GainValue
        };

        enum InputPorts : size_t
        {
          Input
        };

        enum OutputPorts : size_t
        {
          Output
        };

        Gain();

        virtual void signalStep(double timeStep, double time) override;
      };
    }
  }
}