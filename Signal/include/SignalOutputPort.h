#pragma once
#include "SignalPort.h"

namespace ELCT350
{
  namespace Signal
  {
    class SignalOutputPort : public SignalPort
    {
    public:
      void setValue(double value);
    };
  }
}