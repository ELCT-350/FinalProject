#pragma once
#include "Dependent.h"

namespace ELCT350
{
  namespace Signal
  {
    class SignalPort : public Dependent
    {
    public:
      SignalPort();

      virtual void reset() override;

      double getValue() const;
      virtual bool isSet() const override;
    protected:
      double _value;
      bool _valueSet;
    };
  }
}