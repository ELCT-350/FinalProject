#include "Vector.h"
#include <stdexcept>

namespace ELCT350
{
  namespace Math
  {
    template<typename T>
    class Matrix
    {
    public:
      #pragma region Constructors and Destructors
      Matrix(size_t numRows, size_t numColumns)
      {
        //TODO: Implement constructor
      }
      #pragma endregion

      #pragma region Observers
      size_t getNumRows() const
      {
        //TODO: Implement this function
        throw std::logic_error("Not implemented");
      }

      size_t getNumColumns() const
      {
        //TODO: Implement this function
        throw std::logic_error("Not implemented");
      }

      Matrix<T> computeInverse() const
      {
        //We can only compute the inverse for a square matrix, so we throw an exception if it's not square
        size_t size = getNumRows();
        size_t numColums = getNumColumns();
        if (size != getNumColumns())
          throw std::domain_error("Matrix must be square to have an inverse");

        //Get LU Decomposition
        Matrix<T> L(size, size);
        Matrix<T> U(size, size);
        decomposeLU(L, U);

        //Compute the inverse of L and U
        Matrix<T> inverseL(size, size);
        Matrix<T> inverseU(size, size);

        //We can use the fact that matrices are triangular to compute their inverse in a fairly straight-forward way.
        //Ordinarily, for MNA, we would never actually compute the inverse. A minor modification of the below algorithm
        //can be used to solve directly for x in Ax=b (LUx=b after decomposition). In fact, that's kind of what we're doing
        //here, where b is actually I, the identity matrix (matrix with 1s in the diagonal cells, but 0s elsewhere)
        for (size_t row = 0; row < size; ++row)
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
      #pragma endregion

      #pragma region Operators
      const T& operator()(size_t row, size_t column) const
      {
        //TODO: Implement this operator
        throw std::logic_error("Not implemented");
      }

      T& operator()(size_t row, size_t column)
      {
        //If the above const operator works, this will work as well, it just removes the constness
        return const_cast<T&>(const_cast<const Matrix<T>*>(this)->operator()(row, column));
      }

      Matrix<T> operator*(const Matrix<T>& rhs) const
      {
        //TODO: implement this operator
        throw std::logic_error("Not implemented");
      }
      #pragma endregion
    private:
      #pragma region Observers
      void decomposeLU(Matrix<T>& L, Matrix<T>& U) const
      {
        //We assume that L and U are the same size of this matrix and that the matrix is square.
        //We're not checking because this is a private function, so we can control how it's called
        //(and ensure it's checked before this function is called)
        size_t size = getNumRows();

        //Compute the values of U
        for (size_t i = 0; i < size; ++i)
        {
          for (size_t j = i; j < size; ++j)
          {
            T sum = T{}; //initializes to default value for type
            for (size_t k = 0; k < i; ++k)
              sum += L(i,k) * U(k,j);
            U(i,j) = (*this)(i,j) - sum;
          }

          //Compute the values of L
          for (size_t j = i; j < size; ++j)
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