#pragma once
#include "Dependent.h"

namespace ELCT350
{
  namespace Signal
  {
    class OutputPort;
    class InputPort : public Dependent
    {
    public:
      double getValue() const;
      
      //add dependency to OutputPort
      //can be connected to one output port only
      void connect(const OutputPort& port);
      void copyValue();
    private:
      double _value;
      const OutputPort* _connected;
    };
  }
}