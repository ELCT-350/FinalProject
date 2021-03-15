#pragma once
#include <vector>

namespace ELCT350
{
  namespace Signal
  {
    class Dependent
    {
    public:
      bool isReady() const;
      bool areDependenciesSatisfied() const;
      size_t getNumberOfDependencies() const;
      
      void reset();
    protected:
      Dependent();

      void setReady();

      void addDependency(const Dependent& dependency);
    private:
      bool _ready;
      std::vector<const Dependent*> _dependencies;
    };
  }
}