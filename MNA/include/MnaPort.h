#pragma once
#include <memory>

namespace ELCT350
{
  namespace Mna
  {
    class MnaNode;
    class MnaPort
    {
    public:
      #pragma region Constructors
      MnaPort();
      #pragma endregion

      #pragma region Modifiers
      void setAcross(double across);
      void setThrough(double through);
      void setReference();
      void setContainingNode(MnaNode& node);
      #pragma endregion

      #pragma region Observers
      double getAcross() const;
      double getThrough() const;
      bool isReference() const;
      MnaNode& getContainingNode() const;
      #pragma endregion
    private:
      #pragma region Variables
      bool _reference;
      double _across;
      double _through;
      std::shared_ptr<MnaNode> _containingNode;
      #pragma endregion
    };
  }
}