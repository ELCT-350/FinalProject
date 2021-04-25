#pragma once
#include "SimulationBlock.h"
#include "InputPort.h"
#include "OutputPort.h"

namespace ELCT350
{
  namespace Signal
  {
    class SignalBlock : public Dependent, public virtual Common::SimulationBlock
    {
    public:      
      virtual ~SignalBlock();

      void connect(size_t inputPortIndex, const OutputPort& outputPort);
      const OutputPort& getOutputPort(size_t outputPortIndex) const;

      virtual void signalStep(double timeStep, double time) = 0;
      void copyValues();
    protected:
      SignalBlock(size_t numberOfInputPorts, size_t numberOfOutputPorts);

      void setOutputPortValue(size_t outputPortIndex, double value);
      double getInputPortValue(size_t inputPortIndex) const;
      void addDependency(size_t outputPortIndex, size_t inputPortIndex);
    private:
      size_t _numberOfInputPorts;
      size_t _numberOfOutputPorts;
      InputPort* _inputPorts;
      OutputPort* _outputPorts;
    };
  }
}