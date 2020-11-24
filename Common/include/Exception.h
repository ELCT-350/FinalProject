#pragma once
#include <exception>
#include <string>

namespace ELCT350
{
  class Exception : public std::exception
  {
  public:
    #pragma region Variables
    static bool EnableOutput;
    #pragma endregion

    #pragma region Constructors
    Exception(const std::string& message);
    #pragma endregion

    #pragma region exception
    virtual const char* what() const noexcept override;
    #pragma endregion
  private:
    #pragma region Variables
    const std::string _message;
    #pragma endregion
  };
}