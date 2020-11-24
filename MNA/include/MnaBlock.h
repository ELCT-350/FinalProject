#pragma once
#include "SimulationBlock.h"
#include "Matrix.h"
#include "MnaPort.h"

namespace ELCT350
{
  namespace Mna
  {
    class MnaSolver;
    class MnaBlock : public virtual SimulationBlock
    {
    public:
      class Key final
      {
      private:
        Key(){};

        friend class MnaSolver;
      };

      //accessor functions
      double getJacobianValue(size_t row, size_t column) const;
      double getInterceptValue(size_t row) const;

      double getAcross(size_t port) const;
      double getThrough(size_t port) const;

      //auto firstPort = getMnaPort(MnaBlock(), 0);
      size_t getNumMnaPorts() const;
      
      MnaPort& getMnaPort(const Key&, size_t portIndex);

      //generic way of computing current
      void computeThroughValues();
      
      virtual void updateMna(double timeStep, double time, bool nrIteration = false) = 0;
    protected:
      MnaBlock(size_t numPorts);

      //setters
      void setPortReference(size_t portIndex);
      void setJacobianValue(size_t row, size_t column, double value);
      void setInterceptValue(size_t row, double value);
    private:
      const size_t _numPorts;

      MnaPort* _ports;
      Math::Matrix<double> _jacobian;
      Math::Matrix<double> _intercept;
    };
  }
}