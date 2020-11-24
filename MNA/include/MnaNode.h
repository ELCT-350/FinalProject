#pragma once
#include "MnaPort.h"
#include <memory>
#include <set>

namespace ELCT350
{
  namespace Mna
  {
    class MnaNode final : public std::enable_shared_from_this<MnaNode>
    {
    public:
      #pragma region Constructors
      MnaNode(MnaPort& port);
      #pragma endregion

      #pragma region Modifiers
      void setAcross(double value);
      void setNodeIndex(size_t nodeIndex);
      void combineNode(const MnaNode& node);
      #pragma endregion

      #pragma region Observers
      double getAcross() const;    
      size_t getNodeIndex() const;

      bool isReference() const;
      #pragma endregion
    private:
      #pragma region Variables
      std::set<MnaPort*> _ports;
      double _across;      
      size_t _nodeIndex;
      #pragma endregion
    };
  }
}