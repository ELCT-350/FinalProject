#pragma once
#include "SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    class SignalSolver
    {
    public:
      //Initialize internal variables
      SignalSolver(double timeStep);

      //Steps all of the components, in the proper order,
      //and copies port values for connected ports
      void step();

      //Gets the current time within this solver
      double getTime() const;

      //Create a connection between an output port and an input port,
      //Add both the outputBlock and the inputBlock to the set _blocks
      void connect(SignalBlock& outputBlock, size_t outputPortIndex,
                   SignalBlock& inputBlock, size_t inputPortIndex);
    private:
      const double _timeStep;
      double _time;
      std::set<SignalBlock*> _blocks;
    };
  }
}