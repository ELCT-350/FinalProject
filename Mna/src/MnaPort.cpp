#include "MnaPort.h"
#include "MnaNode.h"

using namespace std;
using namespace ELCT350::Mna;

MnaPort::MnaPort()
       : _across(0.0),
         _through(0.0),
         _parentNode(make_shared<Node>(*this))

{
}

void MnaPort::setParentNode(Node& node)
{
  _parentNode = node.shared_from_this();
}

Node& MnaPort::getParentNode()
{
  return *_parentNode;
}