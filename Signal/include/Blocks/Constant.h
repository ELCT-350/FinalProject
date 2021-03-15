#pragma once
#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class Constant : public SignalBlock
      {
      public:
        enum Parameters : size_t
        {
          ConstantValue
        };

        enum OutputPorts : size_t
        {
          Output
        };

        Constant();

        virtual void signalStep(double timeStep, double time) override;
      };
    }
  }
}