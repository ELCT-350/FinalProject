#include "Dependent.h"

using namespace ELCT350::Signal;

void Dependent::addDependency(const Dependent& dependency)
{
  _dependencies.emplace(&dependency);
}

bool Dependent::areDependenciesSatisfied() const
{
  for(const auto* dependency : _dependencies)
  {
    if(!dependency->isSet())
      return false;
  }

  return true;
}