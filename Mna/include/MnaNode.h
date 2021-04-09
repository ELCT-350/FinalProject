#pragma once
#include <memory>
#include <set>

namespace ELCT350
{
  namespace Mna
  {
    class MnaPort;
    class Node final : public std::enable_shared_from_this<Node>
    {
    public:
      //Adds the port to the _ports set
      MnaNode(MnaPort& port);

      //Take all the ports from node, add to our own _ports
      //Remove those ports from the node passed in
      //Every port in node should have its parent node changed to this node
      void joinNode(Node& node);
      void setIndex(size_t index);
      setAcross(double value);

      bool isReference() const;
    private:
      size_t _index;
      std::set<MnaPort*> _ports;
    };
  }
}