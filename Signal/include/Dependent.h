#pragma once
#include <set>

namespace ELCT350
{
  namespace Signal
  {
    class Dependent
    {
    public:
      virtual void reset() = 0;
      virtual bool isSet() const = 0;

      void addDependency(const Dependent& dependency);
      bool areDependenciesSatisfied() const;
    private:
      std::set<const Dependent*> _dependencies;
    };
  }
}