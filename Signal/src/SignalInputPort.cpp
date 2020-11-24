#include "SignalInputPort.h"
#include <exception>

using namespace ELCT350::Signal;
using namespace std;

SignalInputPort::SignalInputPort()
               : _connectedPort(nullptr)
{
}

void SignalInputPort::connect(const SignalOutputPort& port)
{
  _connectedPort = &port;
  addDependency(port);
}

void SignalInputPort::copyValue()
{
  if(!_connectedPort)
    throw exception("Input port not connected");

  if(_connectedPort->isSet())
  {
    _value = _connectedPort->getValue();
    _valueSet = true;
  }
}