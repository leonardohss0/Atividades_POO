#include "Matrix.hpp"
#include <fstream>
#include <iostream>


Matrix::Matrix(int rows, int cols, const double &value)
{
    nRows = rows;
    nCols = cols;

    m = new double *[nRows];
    for (int i = 0; i < nRows; i++)
    {
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++)
        {
            m[i][j] = value;
        }
    }
}

Matrix::Matrix(std::ifstream &myFile) {
    int fRows = 0, fCols = 0;
    myFile >> fRows >> fCols;
    
    this->nRows = fRows;
    this->nCols = fCols;
    this->m = new double *[fRows];

    for (int i = 0; i < fRows; ++i){
        this->m[i] = new double[fCols];
        for (int j = 0; j < fCols; ++j) {
            myFile >> this->m[i][j];
        }       
    }
}

Matrix::Matrix(const Matrix &M)
{
    this->nRows = M.nRows;
    this->nCols = M.nCols;

    m = new double *[nRows];
    for (int i = 0; i < nRows; i++)
    {
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++)
        {
            this->m[i][j] = M.m[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < nRows; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}

void Matrix::print() const
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix Matrix::operator*(const Matrix &M) const
{
    Matrix resultado(this->nRows, M.getCols());
    double aux = 0;

    for (int i = 0; i < this->nRows; i++)
    {
        for (int j = 0; j < M.getCols(); j++)
        {
            for (int n = 0; n < this->nCols; n++)
            {
                aux = this->m[i][n] * M.m[n][j];
                resultado.m[i][j] += aux;
            }
            aux = 0;
        }
    }
    return resultado;
}

Matrix Matrix::operator=(const Matrix &M)
{
    for (int i = 0; i < nRows; i++)
    {
        delete[] m[i];
    }
    delete[] m;

    this->nRows = M.nRows;
    this->nCols = M.nCols;

    this->m = new double *[nRows];
    for (int i = 0; i < this->nRows; i++)
    {
        this->m[i] = new double[nCols];
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = M.m[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator+(const Matrix &M) const
{
    Matrix *sum = new Matrix(M.nRows, M.nCols);
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            sum->m[i][j] = this->m[i][j] + M.m[i][j];
        }
    }

    return *sum;
}

bool Matrix::operator==(const Matrix &M) const
{
    if (this->nCols != M.nCols)
        return false;
    if (this->nRows != M.nRows)
        return false;

    int counter = 0;
    for (int i = 0; i < this->nRows; i++)
    {
        for (int j = 0; j < this->nCols; j++)
        {
            if (this->m[i][j] == M.m[i][j])
            {
                counter++;
            }
        }
    }

    if (counter == nRows * nCols)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Matrix::operator!=(const Matrix &M) const
{
    if (this->nCols != M.nCols)
        return true;
    if (this->nRows != M.nRows)
        return true;

    int counter = 0;
    for (int i = 0; i < this->nRows; i++)
    {
        for (int j = 0; j < this->nCols; j++)
        {
            if (this->m[i][j] == M.m[i][j])
            {
                counter++;
            }
        }
    }

    if (counter == nRows * nCols)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Matrix &Matrix::operator*=(const Matrix &M)
{
    Matrix *sub = new Matrix(this->nRows, M.nCols);

    double sum;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < M.nCols; j++)
        {
            sum = 0;
            for (int k = 0; k < nCols; k++)
            {
                sum += this->m[i][k] * M.m[k][j];
            }
            sub->m[i][j] = sum;
        }
    }

    *this = *sub;

    return *this;
}

Matrix &Matrix::operator*=(int value)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            this->m[i][j] *= value;
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &M)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            this->m[i][j] += M.m[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator-(const Matrix &M) const
{
    Matrix *sub = new Matrix(M.nRows, M.nCols);
    sub->m = new double *[nRows];
    for (int i = 0; i < nRows; i++)
    {
        sub->m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++)
        {
            sub->m[i][j] = this->m[i][j] - M.m[i][j];
        }
    }

    return *sub;
}

Matrix &Matrix::operator-=(const Matrix &M)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            this->m[i][j] -= M.m[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator~() const
{
    Matrix *transp = new Matrix(nCols, nRows);

    transp->m = new double *[transp->nRows];
    for (int i = 0; i < transp->nCols; i++)
    {
        transp->m[i] = new double[transp->nCols];
        for (int j = 0; j < transp->nRows; j++)
        {
            transp->m[i][j] = this->m[j][i];
        }
    }

    return *transp;
}

double &Matrix::operator()(int i, int j) const
{
    return this->m[i][j];
}

double Matrix::getZeroBased(int row, int col) const {
    return this->m[row][col];
}

void Matrix::setValue(int row, int column, double value) {
    this->m[row][column] = value;
}

std::ostream &operator<< (std::ostream &output, const Matrix &A) {
    for (int i = 0; i < A.getRows(); ++i) {
        for (int j = 0; j < A.getCols(); ++j) {
            output << A.getZeroBased(i, j) << " ";
        }
        output << std::endl;
    }
    return output;
}

std::istream &operator>> (std::istream &input, Matrix &A) {
    double value = 0;

    for (int i = 0; i < A.getRows(); ++i) {
        for (int j = 0; j < A.getCols(); ++j) {
            input >> value;
            A.setValue(i, j, value);
        }
    }
    return input;
}
