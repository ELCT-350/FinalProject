#pragma once
#include "MnaBlock.h"

namespace ELCT350
{
  namespace Mna
  {
    class Ground final : public MnaBlock
    {
    public:
      enum MnaPorts
      {
        G
      };

      Ground();

      virtual void updateMna(double timeStep, double time, bool nrIteration) override;
    };
  }
}