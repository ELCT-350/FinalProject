#pragma once

namespace ELCT350
{
  namespace Mna
  {
    class MnaPort final
    {
    public:
      MnaPort();

      void setAcross(double across);
      void setThrough(double through);

      double getAcross() const;
      double getThrough() const;
    private:
      double _across;
      double _through;
      //node port belongs to
    }
  }
}