#pragma once
#include "SignalInputPort.h"
#include "SimulationBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    class SignalBlock : public virtual SimulationBlock, public Dependent
    {
    public:
      virtual ~SignalBlock();
 
      double getOutputPortValue(size_t index);

      void connect(size_t inputPortIndex, const SignalBlock& outputPort, size_t outputPortIndex);
      void copyValues();

      virtual void reset() override;
      virtual bool isSet() const override;

      virtual void updateSignal(double timeStep, double time) = 0;
    protected:
      SignalBlock(size_t numInputPorts, size_t numOutputPorts);

      void addDependency(size_t outputPortIndex, size_t inputPortIndex);
      void setOutputPortValue(size_t index, double value);
      double getInputPortValue(size_t index);
    private:
      const size_t _numInputPorts;
      const size_t _numOutputPorts;

      SignalInputPort* _inputPorts;
      SignalOutputPort* _outputPorts;
    };
  }
}