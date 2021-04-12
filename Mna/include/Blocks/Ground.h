#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    namespace Blocks
    {
      class Ground : public MnaBlock
      {
      public:
        enum MnaPorts : size_t
        {
          G
        };

        Ground();

        virtual void mnaStep(double timeStep, double time) override;
      };
    }
  }
}