#include "SignalPort.h"

using namespace ELCT350::Signal;

SignalPort::SignalPort()
          : _value(0.0), _valueSet(false)
{
}

void SignalPort::reset()
{
  _valueSet = false;
}

double SignalPort::getValue() const
{
  return _value;
}

bool SignalPort::isSet() const
{
  return _valueSet;
}