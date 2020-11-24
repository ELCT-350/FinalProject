#include "Exception.h"
#include <iostream>

using namespace ELCT350;
using namespace std;

bool Exception::EnableOutput = true;

#pragma region Constructors
Exception::Exception(const string& message)
         : _message(message)
{
  if(EnableOutput)
    cerr << "Exception: " << message;
}
#pragma endregion

#pragma region exception
const char* Exception::what() const noexcept
{
  return _message.c_str();
}
#pragma endregion