#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    namespace Blocks
    {
      class Resistor : public MnaBlock
      {
      public:
        enum Parameters : size_t
        {
          Resistance
        };

        enum MnaPorts : size_t
        {
          P,
          N
        };

        Resistor();

        virtual void mnaStep(double timeStep, double time) override;
      };
    }
  }
}