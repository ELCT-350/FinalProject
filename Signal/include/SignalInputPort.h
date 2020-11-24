#pragma once
#include "SignalOutputPort.h"

namespace ELCT350
{
  namespace Signal
  {
    class SignalInputPort : public SignalPort
    {
    public:
      SignalInputPort();

      void copyValue();
      void connect(const SignalOutputPort& port);
    private:
      const SignalOutputPort* _connectedPort;
    };
  }
}