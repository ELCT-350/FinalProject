#pragma once

namespace ELCT350
{
  namespace Math
  {
    template<typename T>
    class Matrix
    {
    public:
      #pragma region Constructors
      Matrix(size_t rowSize, size_t columnSize)
        : _rowSize(rowSize), _columnSize(columnSize),
          _rows(new T[_rowSize])
      {
        for(size_t row = 0; row < _rowSize; ++row)
          _rows[row] = new T[_columnSize];

        clear();
      }
      #pragma endregion

      #pragma region Modifiers
      void Matrix::clear()
      {
        for(size_t row = 0; row < _rowSize; ++row)
          for(size_t column = 0; column < _columnSize; ++column)
            _rows[rows][column] = T{};
      }

      void Matrix::setColumn(size_t index, const Matrix<T>& vector)
      {
        throw exception("Not implemented");
      }
      #pragma endregion

      #pragma region Observers
      Matrix<T> computeInverse() const
      {
        //We can only compute the inverse for a square matrix, so we throw an exception if it's not square
        if (_rowSize != _columnSize)
          throw std::domain_error("Matrix must be square to have an inverse");

        //Get LU Decomposition
        Matrix<T> L(_rowSize, _columnSize);
        Matrix<T> U(_rowSize, _columnSize);
        decomposeLU(L, U);

        //Compute the inverse of L and U
        Matrix<T> inverseL(_rowSize, _columnSize);
        Matrix<T> inverseU(_rowSize, _columnSize);

        //We can use the fact that matrices are triangular to compute their inverse in a fairly straight-forward way.
        //Ordinarily, for MNA, we would never actually compute the inverse. A minor modification of the below algorithm
        //can be used to solve directly for x in Ax=b (LUx=b after decomposition). In fact, that's kind of what we're doing
        //here, where b is actually I, the identity matrix (matrix with 1s in the diagonal cells, but 0s elsewhere)
        for (size_t row = 0; row < _rowSize; ++row)
        {
          inverseL(row,row) = static_cast<T>(1) / L(row,row);
          inverseU(row,row) = static_cast<T>(1) / U(row,row);
          for (size_t l = 0; l < row; ++l)
          {
            for (size_t j = 0; j < row; ++j)
            {
              inverseL(row,l) -= (L(row,j) * inverseL(j,l)) / L(row,row);
              inverseU(l,row) -= inverseU(l,j) * U(j,row) / U(row,row);
            }
          }
        }

        //return U^(-1)*L^(-1), which is the inverse of the matrix
        return inverseU * inverseL;
      }

      size_t getRowSize() const
      {
        throw exception("Not implemented");
      }

      size_t getColumnSize() const
      {
        throw exception("Not implemented");
      }

      Matrix<T> getRow(size_t rowIndex) const
      {
        throw exception("Not implemented");
      }

      Matrix<T> getColumn(size_t columnIndex) const
      {
        throw exception("Not implemented");
      }
      #pragma endregion

      #pragma region Operators
      #pragma region Modifiers
      Matrix<T>& operator=(const Matrix& rhs)
      {
        throw exception("Not implemented");
      }
      #pragma endregion

      #pragma region Observers
      Matrix<T> operator+(const Matrix<T>& rhs) const
      {
        throw exception("Not implemented");
      }

      Matrix<T> operator*(const Matrix<T>& rhs) const
      {
        throw exception("Not implemented");
      }

      const T& operator()(size_t row, size_t column) const
      {
        return _rows[row][column];
      }

      T& operator()(size_t row, size_t column)
      {
        return const_cast<T&>(const_cast<const Matrix<T>*>(this)->operator()(row, column));
      }
      #pragma endregion
      #pragma endregion
    private:
      #pragma region Variables
      const size_t _rowSize;
      const size_t _columnSize;
      T** _rows;
      #pragma endregion

      #pragma region Observers
      void decomposeLU(Matrix<T>& L, Matrix<T>& U) const
      {
        //We assume that L and U are the same size of this matrix and that the matrix is square.
        //We're not checking because this is a private function, so we can control how it's called
        //(and ensure it's checked before this function is called)

        //Compute the values of U
        for (size_t i = 0; i < _rowSize; ++i)
        {
          for (size_t j = i; j < _rowSize; ++j)
          {
            T sum = T{}; //initializes to default value for type
            for (size_t k = 0; k < i; ++k)
              sum += L(i,k) * U(k,j);
            U(i,j) = (*this)(i,j) - sum;
          }

          //Compute the values of L
          for (size_t j = i; j < _rowSize; ++j)
          {
            if (i == j)
              L(i,j) = 1;
            else
            {
              T sum = T{};
              for (size_t k = 0; k < i; ++k)
                sum += L(j,k) * U(k,i);

              L(j,i) = ((*this)(j,i) - sum) / U(i,i);
            }
          }
        }
      }
      #pragma endregion
    };
  }
}