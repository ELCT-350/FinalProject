#pragma once
#include "SimulationBlock.h"
#include "Matrix.h"
#include "Vector.h"

namespace ELCT350
{
  namespace Mna
  {
    class MnaPort;
    class MnaBlock : public virtual Common::SimulationBlock
    {
    public:
      virtual ~MnaBlock();
      virtual void mnaStep(double timeStep, double time) = 0;

      void computeThroughValues();
      void setReference(size_t port);

      double getJacobianValue(size_t row, size_t column) const;
      double getInterceptValue(size_t row) const;
      double getAcross(size_t port) const;
      double getThrough(size_t port) const;
      MnaPort& getMnaPort(size_t port) const;
    protected:
      MnaBlock(size_t numberOfMnaPorts);

      void setJacobianValue(size_t row, size_t column, double value);
      void setInterceptValue(size_t row, double value);
    private:
      size_t _numberOfMnaPorts;
      MnaPort* _ports;

      Math::Matrix<double>* _jacobian;
      Math::Vector<double>* _intercept;
    };
  }
}