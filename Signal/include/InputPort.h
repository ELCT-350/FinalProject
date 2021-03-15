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
      //check to see if a dependency already exists before adding this
      //dependency
      void connect(const OutputPort& port);
      void copyValue();
    private:
      double _value;
    };
  }
}