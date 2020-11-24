#include "MnaPort.h"
#include "MnaNode.h"

using namespace ELCT350::Mna;
using namespace std;

#pragma region Constructor
MnaPort::MnaPort()
       : _reference(false), _across(0.0), _through(0.0),
         _containingNode(make_shared<MnaNode>(*this))
{
}
#pragma endregion

 void MnaPort::setContainingNode(MnaNode& node)
 {
   _containingNode = node.shared_from_this();
 }