#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include <istream>

// contrutor default - cria uma matriz vazia com nRows = nCols = 0
Matrix::Matrix()
{
    nRows = 0.0;
    nCols = 0.0;
    m = NULL;
}

Matrix::Matrix(int rows, int cols, const double &value)
{
    this->nRows = rows;
    this->nCols = cols;

    this->m = new double *[rows];

    for (int i = 0; i < this->nRows; ++i)
    {
        m[i] = new double[cols];
        for (int j = 0; j < this->nCols; ++j)
            this->m[i][j] = value;
    }
}

Matrix::Matrix(std::ifstream &myFile)
{
    int fRows = 0, fCols = 0;
    myFile >> fRows >> fCols;

    this->nRows = fRows;
    this->nCols = fCols;
    this->m = new double *[fRows];

    for (int i = 0; i < fRows; ++i)
    {
        this->m[i] = new double[fCols];
        for (int j = 0; j < fCols; ++j)
        {
            myFile >> this->m[i][j];
        }
    }
}

Matrix::Matrix(const Matrix &that)
{
    this->nRows = that.getRows();
    this->nCols = that.getCols();

    this->m = new double *[this->nRows];

    for (int i = 0; i < that.getRows(); i++)
    {
        this->m[i] = new double[this->nCols];
        for (int j = 0; j < that.getCols(); j++)
            this->m[i][j] = that.m[i][j];
    }
}

Matrix::~Matrix()
{
    if (this->getRows() >= 0 && this->getCols() >= 0)
    {
        for (int i = 0; i < this->getRows(); ++i)
            delete[] this->m[i];
        delete[] this->m;
    }
}

// Permite ao usuario usar 1 based indexing.
double Matrix::get(int row, int col) const
{
    if (this->getRows() >= row && row > 0)
    {
        if (this->getCols() >= col && col > 0)
            return m[row - 1][col - 1];
    }
    return -1;
}

double Matrix::getZeroBased(int row, int col) const
{
    if (this->getRows() > row && row >= 0)
    {
        if (this->getCols() > col && col >= 0)
            return m[row][col];
    }
    return -1;
}

void Matrix::setZeroBased(int row, int col, double value)
{
    if (this->getRows() > row && row >= 0)
    {
        if (this->getCols() > col && col >= 0)
            this->m[row][col] = value;
    }
    else
        std::cout << "Invalid position" << std::endl;
}

void Matrix::print() const
{
    if (this->getCols() > 0 && this->getRows() > 0)
    {
        for (int i = 0; i < this->getRows(); ++i)
        {
            for (int j = 0; j < this->getCols(); ++j)
            {
                std::cout << this->m[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}

// Faz com que a matriz torne-se uma matriz identidade
void Matrix::unit()
{
    if (this->getRows() == this->getCols())
    {
        for (int i = 0; i < this->getRows(); i++)
        {
            for (int j = 0; j < this->getCols(); j++)
            {
                if (i == j)
                    m[i][j] = 1;
                else
                    m[i][j] = 0;
            }
        }
    }
}

// Faz com que a matriz torne-se uma matriz nula
void Matrix::zeros()
{
    for (int i = 0; i < this->getRows(); ++i)
    {
        for (int j = 0; j < this->getCols(); ++j)
            m[i][j] = 0;
    }
}

void Matrix::ones()
{
    for (int i = 0; i < this->getRows(); ++i)
    {
        for (int j = 0; j < this->getCols(); ++j)
            m[i][j] = 1;
    }
}

double &Matrix::operator()(int i, int j)
{
    return this->m[i][j];
}

void Matrix::operator=(const Matrix &A)
{
    if (*(this) == A)
        return;
    for (int i = 0; i < this->getRows(); ++i)
    {
        delete[] this->m[i];
    }
    delete[] this->m;

    this->nCols = A.getCols();
    this->nRows = A.getRows();
    this->m = new double *[A.getRows()];

    for (int i = 0; i < A.getRows(); ++i)
    {
        this->m[i] = new double[this->getCols()];
        for (int j = 0; j < A.getCols(); ++j)
        {
            this->m[i][j] = A.getZeroBased(i, j);
        }
    }
}

bool Matrix::operator==(const Matrix &A) const
{
    if (this->getRows() != A.getRows() ||
        this->getCols() != A.getCols())
        return false;
    for (int i = 0; i < this->getRows(); ++i)
    {
        for (int j = 0; j < this->getCols(); ++j)
        {
            if (this->getZeroBased(i, j) != A.getZeroBased(i, j))
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &A) const
{
    if (this->getRows() != A.getRows() ||
        this->getCols() != A.getCols())
        return true;
    for (int i = 0; i < this->getRows(); ++i)
    {
        for (int j = 0; j < this->getCols(); ++j)
        {
            if (this->getZeroBased(i, j) != A.getZeroBased(i, j))
                return true;
        }
    }
    return false;
}

Matrix Matrix::operator+(const Matrix &A) const
{
    if (A.getCols() == this->getCols() &&
        A.getRows() == this->getRows())
    {
        Matrix sumMatrix(A.getCols(), A.getRows());
        for (int i = 0; i < sumMatrix.getRows(); ++i)
        {
            for (int j = 0; j < sumMatrix.getCols(); ++j)
            {
                sumMatrix.m[i][j] = A.getZeroBased(i, j) + this->getZeroBased(i, j);
            }
        }
        return sumMatrix;
    }
    std::cout << "Not allowed to sum matrix of different dimensions" << std::endl;
    return *this;
}

Matrix Matrix::operator-(const Matrix &A) const
{
    if (A.getCols() == this->getCols() &&
        A.getRows() == this->getRows())
    {
        Matrix diffMatrix(A.getCols(), A.getRows());
        for (int i = 0; i < diffMatrix.getRows(); ++i)
        {
            for (int j = 0; j < diffMatrix.getCols(); ++j)
            {
                diffMatrix.m[i][j] = this->getZeroBased(i, j) - A.getZeroBased(i, j);
            }
        }
        return diffMatrix;
    }
    std::cout << "Not allowed to sum matrix of different dimensions" << std::endl;
    return *this;
}

Matrix Matrix::operator*(const Matrix &A) const
{
    if (A.getRows() == this->getCols())
    {
        Matrix multMatrix(this->getRows(), A.getCols());
        for (int i = 0; i < this->getRows(); ++i)
        {
            for (int j = 0; j < A.getCols(); ++j)
            {
                for (int k = 0; k < this->getCols(); ++k)
                {
                    multMatrix.m[i][j] += this->getZeroBased(i, k) * A.getZeroBased(k, j);
                }
            }
        }
        return multMatrix;
    }
    std::cout << "Bad dimensions for Matrix multiplication" << std::endl;
    return *this;
}

void Matrix::operator-=(const Matrix &A)
{
    if (A.getCols() == this->getCols() &&
        A.getRows() == this->getRows())
    {
        for (int i = 0; i < A.getRows(); ++i)
        {
            for (int j = 0; j < A.getCols(); ++j)
            {
                this->m[i][j] -= A.getZeroBased(i, j);
            }
        }
    }
    else
    {
        std::cout << "Not allowed to subtrack matrix of different dimensions" << std::endl;
    }
}

void Matrix::operator+=(const Matrix &A)
{
    if (A.getCols() == this->getCols() &&
        A.getRows() == this->getRows())
    {
        for (int i = 0; i < A.getRows(); ++i)
        {
            for (int j = 0; j < A.getCols(); ++j)
            {
                this->m[i][j] += A.getZeroBased(i, j);
            }
        }
    }
    else
    {
        std::cout << "Not allowed to sum matrix of different dimensions" << std::endl;
    }
}

void Matrix::operator*=(int n)
{
    if (this->getRows() > 0 && this->getCols() > 0)
    {
        for (int i = 0; i < this->getRows(); ++i)
        {
            for (int j = 0; j < this->getCols(); ++j)
            {
                this->m[i][j] += this->getZeroBased(i, j);
            }
        }
    }
}

void Matrix::operator*=(Matrix &A)
{
    if (A.getRows() == this->getCols())
    {
        Matrix result(this->getRows(), A.getCols());
        for (int i = 0; i < this->getRows(); ++i)
        {
            for (int j = 0; j < A.getCols(); ++j)
            {
                for (int k = 0; k < this->getCols(); ++k)
                {
                    result.setZeroBased(i, j, result.getZeroBased(i, j) + this->getZeroBased(i, k) * A.getZeroBased(k, j));
                }
            }
        }
        *(this) = result;
    }
}

Matrix Matrix::operator~() const
{
    Matrix transposed(this->getCols(), this->getRows());
    for (int i = 0; i < this->getRows(); ++i)
    {
        for (int j = 0; j < this->getCols(); ++j)
        {
            transposed.setZeroBased(i, j, this->getZeroBased(j, i));
        }
    }
    return transposed;
}

std::ostream &operator<<(std::ostream &output, const Matrix &A)
{
    for (int i = 0; i < A.getRows(); ++i)
    {
        for (int j = 0; j < A.getCols(); ++j)
        {
            output << A.getZeroBased(i, j) << " ";
        }
        output << std::endl;
    }
    return output;
}

std::istream &operator>>(std::istream &input, Matrix &A)
{
    double value = 0;

    for (int i = 0; i < A.getRows(); ++i)
    {
        for (int j = 0; j < A.getCols(); ++j)
        {
            input >> value;
            A.setZeroBased(i, j, value);
        }
    }
    return input;
}

void Matrix::print() const
{
    if (this->getCols() > 0 && this->getRows() > 0)
    {
        for (int i = 0; i < this->getRows(); ++i)
        {
            for (int j = 0; j < this->getCols(); ++j)
            {
                std::cout << this->m[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}

// Faz com que a matriz torne-se uma matriz identidade
void Matrix::unit()
{
    if (this->getRows() == this->getCols())
    {
        for (int i = 0; i < this->getRows(); i++)
        {
            for (int j = 0; j < this->getCols(); j++)
            {
                if (i == j)
                    m[i][j] = 1;
                else
                    m[i][j] = 0;
            }
        }
    }
}

// Faz com que a matriz torne-se uma matriz nula
void Matrix::zeros()
{
    for (int i = 0; i < this->getRows(); ++i)
    {
        for (int j = 0; j < this->getCols(); ++j)
            m[i][j] = 0;
    }
}

void Matrix::ones()
{
    for (int i = 0; i < this->getRows(); ++i)
    {
        for (int j = 0; j < this->getCols(); ++j)
            m[i][j] = 1;
    }
}
