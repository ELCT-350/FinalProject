#pragma once
#include <stdexcept>

namespace ELCT350
{
  namespace Math
  {
    template<typename T>
    class Vector
    {
    public:
      Vector(size_t size)
        : _size(size),
          _data(new T[size])
      {
        if(_data)
        {
          for(size_t i = 0; i < _size; ++i)
            _data[i] = T{};
        }
      }

      Vector(const Vector<T>& original)
        : _size(original._size),
          _data(new T[_size])
      {
        if(_data)
        {
          for(size_t i = 0; i < _size; ++i)
            _data[i] = original._data[i];
        }
      }

      Vector(Vector<T>&& old)
        : _size(old._size),
          _data(old._data)
      {
        old._size = 0;
        old._data = nullptr;
      }

      ~Vector()
      {
        if(_data)
          delete[] _data;
      }

      T& operator[](size_t i)
      {
        if(i >= _size)
          throw std::out_of_range("i");

        return _data[i];
      }

      Vector<T> operator*(const T& scalar) const
      {
        Vector<T> product(_size);
        for(size_t i = 0; i < _size; ++i)
          product[i] = _data[i] * scalar;
        return product;
      }

    private:
      size_t _size;
      T* _data;
    };
  }
}