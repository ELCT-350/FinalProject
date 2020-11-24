#include "SignalOutputPort.h"

using namespace ELCT350::Signal;

void SignalOutputPort::setValue(double value)
{
  _value = value;
  _valueSet = true;
}