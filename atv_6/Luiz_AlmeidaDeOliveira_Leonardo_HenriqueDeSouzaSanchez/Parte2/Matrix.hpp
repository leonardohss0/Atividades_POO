#ifndef __MATRIX_H
#define __MATRIX_H

#include "Exception.hpp"
#include <fstream>
#include <iostream>
#include <istream>

template <class T> class Matrix {
private:
  T **m;     // m é um array 2D a ser implementado como um pointer de pointers
  int nRows; // numero de linhas
  int nCols; //  numero de colunas

public:
  // Construtores
  Matrix(int rows = 0, int cols = 0, const T &value = 0.0);
  Matrix(std::ifstream &myFile);
  Matrix(const Matrix &that);
  // destrutor
  ~Matrix();

  // basic getters
  inline int getRows() const { return this->nRows; }
  inline int getCols() const { return this->nCols; }
  T get(int row, int col) const;
  T getZeroBased(int row, int col) const;

  // overloaded operators
  T &operator()(int i, int j);
  Matrix<T> operator+(const Matrix &C) const;
  Matrix<T> operator*(const Matrix<T> &A) const;
  ;
  Matrix<T> operator-(const Matrix &A) const;
  bool operator==(const Matrix &A) const;
  bool operator!=(const Matrix &A) const;
  void operator=(const Matrix &A);
  void operator-=(const Matrix &A);
  void operator+=(const Matrix &A);
  void operator*=(int n);
  void operator*=(Matrix &A);
  Matrix<T> operator~() const;
  void setZeroBased(int row, int col, T value);
  friend std::ostream &operator<<(std::ostream &output, const Matrix<T> &A) {
    for (int i = 0; i < A.getRows(); ++i) {
      for (int j = 0; j < A.getCols(); ++j) {
        output << A.getZeroBased(i, j) << " ";
      }
      output << std::endl;
    }
    return output;
  }
  friend std::istream &operator>>(std::istream &input, Matrix<T> &A) {
    T value = 0;

    for (int i = 0; i < A.getRows(); ++i) {
      for (int j = 0; j < A.getCols(); ++j) {
        input >> value;
        A.setZeroBased(i, j, value);
      }
    }
    return input;
  }
  // other methods
  void print() const;
  void unit();
  void zeros();
  void ones();
};

template <class T> Matrix<T>::Matrix(int rows, int cols, const T &value) {
  this->nRows = rows;
  this->nCols = cols;

  this->m = new T *[rows];

  for (int i = 0; i < this->nRows; ++i) {
    m[i] = new T[cols];
    for (int j = 0; j < this->nCols; ++j)
      this->m[i][j] = value;
  }
}

template <class T> Matrix<T>::Matrix(std::ifstream &myFile) {
  int fRows = 0, fCols = 0;
  myFile >> fRows >> fCols;

  this->nRows = fRows;
  this->nCols = fCols;
  this->m = new T *[fRows];

  for (int i = 0; i < fRows; ++i) {
    this->m[i] = new T[fCols];
    for (int j = 0; j < fCols; ++j) {
      myFile >> this->m[i][j];
    }
  }
}

template <class T> void Matrix<T>::setZeroBased(int row, int col, T value) {
  if (this->getRows() > row && row >= 0) {
    if (this->getCols() > col && col >= 0)
      this->m[row][col] = value;
  }
  throw Exception("Numero de linha e/ou coluna invalida!");
}

template <class T> Matrix<T>::Matrix(const Matrix<T> &that) {
  this->nRows = that.getRows();
  this->nCols = that.getCols();

  this->m = new T *[this->nRows];

  for (int i = 0; i < that.getRows(); i++) {
    this->m[i] = new T[this->nCols];
    for (int j = 0; j < that.getCols(); j++)
      this->m[i][j] = that.m[i][j];
  }
}

template <class T> Matrix<T>::~Matrix() {
  if (this->getRows() >= 0 && this->getCols() >= 0) {
    for (int i = 0; i < this->getRows(); ++i)
      delete[] this->m[i];
    delete[] this->m;
  }
}

template <class T> T Matrix<T>::get(int row, int col) const {
  if (this->getRows() >= row && row > 0) {
    if (this->getCols() >= col && col > 0)
      return m[row - 1][col - 1];
  }
  throw Exception("Posicao de linha e/ou coluna invalida!");
}

template <class T> T Matrix<T>::getZeroBased(int row, int col) const {
  if (this->getRows() > row && row >= 0) {
    if (this->getCols() > col && col >= 0)
      return m[row][col];
  }
  throw Exception("Posicao de linha e/ou coluna invalida!");
}

template <class T> void Matrix<T>::print() const {
  if (this->getCols() > 0 && this->getRows() > 0) {
    for (int i = 0; i < this->getRows(); ++i) {
      for (int j = 0; j < this->getCols(); ++j) {
        std::cout << this->m[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }
}

// Faz com que a matriz torne-se uma matriz identidade
template <class T> void Matrix<T>::unit() {
  if (this->getRows() == this->getCols()) {
    for (int i = 0; i < this->getRows(); i++) {
      for (int j = 0; j < this->getCols(); j++) {
        if (i == j)
          m[i][j] = 1;
        else
          m[i][j] = 0;
      }
    }
  }
}

// Faz com que a matriz torne-se uma matriz nula
template <class T> void Matrix<T>::zeros() {
  for (int i = 0; i < this->getRows(); ++i) {
    for (int j = 0; j < this->getCols(); ++j)
      m[i][j] = 0;
  }
}

template <class T> void Matrix<T>::ones() {
  for (int i = 0; i < this->getRows(); ++i) {
    for (int j = 0; j < this->getCols(); ++j)
      m[i][j] = 1;
  }
}

template <class T> T &Matrix<T>::operator()(int i, int j) {
  if (this->getRows() > i && i >= 0) {
    if (this->getCols() > j && j >= 0)
      return this->m[i][j];
  } else
    throw Exception("Posicao de linha e/ou coluna invalida!");
}

template <class T> void Matrix<T>::operator=(const Matrix<T> &A) {
  if (*(this) == A)
    return;
  for (int i = 0; i < this->getRows(); ++i) {
    delete[] this->m[i];
  }
  delete[] this->m;

  this->nCols = A.getCols();
  this->nRows = A.getRows();
  this->m = new T *[A.getRows()];

  for (int i = 0; i < A.getRows(); ++i) {
    this->m[i] = new T[this->getCols()];
    for (int j = 0; j < A.getCols(); ++j) {
      this->m[i][j] = A.getZeroBased(i, j);
    }
  }
}

template <class T> bool Matrix<T>::operator==(const Matrix<T> &A) const {
  if (this->getRows() != A.getRows() || this->getCols() != A.getCols())
    return false;
  for (int i = 0; i < this->getRows(); ++i) {
    for (int j = 0; j < this->getCols(); ++j) {
      if (this->getZeroBased(i, j) != A.getZeroBased(i, j))
        return false;
    }
  }
  return true;
}

template <class T> bool Matrix<T>::operator!=(const Matrix<T> &A) const {
  if (this->getRows() != A.getRows() || this->getCols() != A.getCols())
    return true;
  for (int i = 0; i < this->getRows(); ++i) {
    for (int j = 0; j < this->getCols(); ++j) {
      if (this->getZeroBased(i, j) != A.getZeroBased(i, j))
        return true;
    }
  }
  return false;
}

template <class T> Matrix<T> Matrix<T>::operator+(const Matrix<T> &A) const {
  if (A.getCols() == this->getCols() && A.getRows() == this->getRows()) {
    Matrix<T> sumMatrix(A.getCols(), A.getRows());
    for (int i = 0; i < sumMatrix.getRows(); ++i) {
      for (int j = 0; j < sumMatrix.getCols(); ++j) {
        sumMatrix.m[i][j] = A.getZeroBased(i, j) + this->getZeroBased(i, j);
      }
    }
    return sumMatrix;
  }
  throw Exception("Not allowed to sum matrix of different dimensions");
}

template <class T> Matrix<T> Matrix<T>::operator-(const Matrix<T> &A) const {
  if (A.getCols() == this->getCols() && A.getRows() == this->getRows()) {
    Matrix<T> diffMatrix(A.getCols(), A.getRows());
    for (int i = 0; i < diffMatrix.getRows(); ++i) {
      for (int j = 0; j < diffMatrix.getCols(); ++j) {
        diffMatrix.m[i][j] = this->getZeroBased(i, j) - A.getZeroBased(i, j);
      }
    }
    return diffMatrix;
  }
  throw Exception("Not allowed to sum matrix of different dimensions");
}

template <class T> Matrix<T> Matrix<T>::operator*(const Matrix<T> &A) const {
  if (A.getRows() == this->getCols()) {
    Matrix<T> multMatrix(this->getRows(), A.getCols());
    for (int i = 0; i < this->getRows(); ++i) {
      for (int j = 0; j < A.getCols(); ++j) {
        for (int k = 0; k < this->getCols(); ++k) {
          multMatrix.m[i][j] += this->getZeroBased(i, k) * A.getZeroBased(k, j);
        }
      }
    }
    return multMatrix;
  } else
    throw Exception("Bad dimensions for Matrix multiplication");
}

template <class T> void Matrix<T>::operator-=(const Matrix<T> &A) {
  if (A.getCols() == this->getCols() && A.getRows() == this->getRows()) {
    for (int i = 0; i < A.getRows(); ++i) {
      for (int j = 0; j < A.getCols(); ++j) {
        this->m[i][j] -= A.getZeroBased(i, j);
      }
    }
  } else
    throw Exception("Not allowed to sum matrix of different dimensions");
}

template <class T> void Matrix<T>::operator+=(const Matrix<T> &A) {
  if (A.getCols() == this->getCols() && A.getRows() == this->getRows()) {
    for (int i = 0; i < A.getRows(); ++i) {
      for (int j = 0; j < A.getCols(); ++j) {
        this->m[i][j] += A.getZeroBased(i, j);
      }
    }
  } else
    throw Exception("Not allowed to sum matrix of different dimensions");
}

template <class T> void Matrix<T>::operator*=(int n) {
  if (this->getRows() > 0 && this->getCols() > 0) {
    for (int i = 0; i < this->getRows(); ++i) {
      for (int j = 0; j < this->getCols(); ++j) {
        this->m[i][j] += this->getZeroBased(i, j);
      }
    }
  }
}

template <class T> void Matrix<T>::operator*=(Matrix<T> &A) {
  if (A.getRows() == this->getCols()) {
    Matrix<T> result(this->getRows(), A.getCols());
    for (int i = 0; i < this->getRows(); ++i) {
      for (int j = 0; j < A.getCols(); ++j) {
        for (int k = 0; k < this->getCols(); ++k) {
          result.setZeroBased(i, j,
                              result.getZeroBased(i, j) +
                                  this->getZeroBased(i, k) *
                                      A.getZeroBased(k, j));
        }
      }
    }
    *(this) = result;
  }
}

template <class T> Matrix<T> Matrix<T>::operator~() const {
  Matrix<T> transposed(this->getCols(), this->getRows());
  for (int i = 0; i < this->getRows(); ++i) {
    for (int j = 0; j < this->getCols(); ++j) {
      transposed.setZeroBased(i, j, this->getZeroBased(j, i));
    }
  }
  return transposed;
}

#endif