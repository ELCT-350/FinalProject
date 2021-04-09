#pragma once
#include <set>
#include "MnaBlock.h"
#include "MnaNode.h"

namespace ELCT350
{
  namespace Mna
  {
    class MnaSolver final
    {
    public:
      MnaSolver(double timeStep);

      void connect(MnaBlock& block1, size_t port1,
                   MnaBlock& block2, size_t port2);
      void step();
      
      double getTime() const;
    private:
      double _timeStep;
      double _time;

      std::set<MnaBlock*> _blocks;
    };
  }
}