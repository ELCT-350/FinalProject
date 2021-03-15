#pragma once
#include "SignalBlock.h"
#include <set>

namespace ELCT350
{
  namespace Signal
  {
    class SignalSolver
    {
    public:
      SignalSolver(double timeStep);

      //1. Add outputBlock and inputBlock to your block list
      //2. Connect ports (connect input port to an output port)
      void connect(SignalBlock& outputBlock, size_t outputPort,
                   SignalBlock& inputBlock, size_t inputPort);

      //
      void step();
      
      double getTime() const;
    private:
      double _timeStep;
      double _time;

      std::set<SignalBlock*> _blocks;
    };
  }
}