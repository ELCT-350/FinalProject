#pragma once
#include "Dependent.h"

namespace ELCT350
{
  namespace Signal
  {
    class InputPort;
    class OutputPort : public Dependent
    {
    public:
      double getValue() const;
      
      void setValue(double value);
      void addDependency(const InputPort& port);
    private:
      double _value;
    };
  }
}