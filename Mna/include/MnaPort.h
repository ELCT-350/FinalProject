#pragma once
#include <memory>

namespace ELCT350
{
  namespace Mna
  {
    class Node;
    class MnaPort final
    {
    public:
      //Create a node
      MnaPort();

      void setAcross(double across);
      void setThrough(double through);
      void setReference(bool reference);
      void setParentNode(Node& node);

      double getAcross() const;
      double getThrough() const;
      bool getReference() const;
      Node& getParentNode();
    private:
      double _across;
      double _through;
      bool _isReference;
      //node port belongs to
      std::shared_ptr<Node> _parentNode;
    };
  }
}