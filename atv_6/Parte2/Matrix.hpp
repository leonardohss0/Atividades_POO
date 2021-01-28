#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

template <class TValor>
class Matrix;

template <class TValor>
std::ostream &operator<<(std::ostream &output, const Matrix<TValor> &A);
template <class TValor>
class Matrix
{

private:
    Tvalor **m;   // m é um array 2D a ser implementado como um pointer de pointers
    Tvalor nRows; // numero de linhas
    Tvalor nCols; //  numero de colunas

public:
    //Construtores
    Matrix();
    Matrix(Tvalor rows, Tvalor colunas);
    Matrix(Tvalor rows = 0, Tvalor cols = 0, const TValor &valor = 0.0);
    Matrix(const Matrix<TValor> &matriz);
    // Destrutor
    ~Matrix();

    TValor &operator()(const int, const int) const;

    // basic getters
    inline int getRows() const { return this->nRows; }
    inline int getCols() const { return this->nCols; }
    double get(int row, int col) const;
    double getZeroBased(int row, int col) const;

    // overloaded operators
    double &operator()(int i, int j);
    Matrix operator+(const Matrix &C) const;
    Matrix operator*(const Matrix &A) const;
    Matrix operator-(const Matrix &A) const;
    bool operator==(const Matrix &A) const;
    bool operator!=(const Matrix &A) const;
    void operator=(const Matrix &A);
    void operator-=(const Matrix &A);
    void operator+=(const Matrix &A);
    void operator*=(int n);
    void operator*=(Matrix &A);
    Matrix operator~() const;
    void setZeroBased(int row, int col, double value);
    friend std::ostream &operator<<(std::ostream &output, const Matrix &A);
    friend std::istream &operator>>(std::istream &input, Matrix &A);

    // other methods
    void print() const;
    void unit();
    void zeros();
    void ones();
};

#endif
