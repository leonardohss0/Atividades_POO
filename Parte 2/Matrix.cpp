#include "Matrix.hpp"
#include <fstream>
#include <iostream>

using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0
Matrix::Matrix()
{
    nRows = 0.0;
    nCols = 0.0;
    m = NULL;
}

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
/*
Matrix::Matrix(std::ifstream &myFile)
{
    while (!myFile.eof())
    {

        std::string data;
        getline(myFile, data);

        nRows = (int)data[0] - 48;
        nCols = (int)data[2] - 48;

        m = new double *[nRows];
        for (int i = 0; i < nRows; i++)
        {
            m[i] = new double[nCols];
        }

        std::string aux;

        for (int j = 0; j < nRows; j++)
        {
            int val = 0;
            getline(myFile, aux);
            for (int k = 0; k < nCols; k++)
            {
                m[j][k] = (double)aux[val] - 48.0;
                val = val + 2;
            }
        }
    }
}*/

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

/*
std::ostream& operator<< (std::ostream& op, const Matrix &M){
    for(int i = 0; i < M.nRows; i++){
        for(int j = 0; j < M.nCols; j++){
            op << M.m[i][j] << ' ';
        }
        op << std::endl;
    }
    return op;
}

std::istream& operator>>(std::istream &op, Matrix &M)
{
    for (int i = 0; i < M.getRows(); i++)
    {
        delete[] M.m[i];
    }
    delete[] M.m;

    std::cout << "\nDigite o numero de linhas: " << std::endl;
    op >> M.nRows;
    std::cout << "\nDigite o numero de colunas: " << std::endl;
    op >> M.nCols;

    std::cout << "\nDigite os valores: " << std::endl;
    M.m = new double *[M.nRows];
    for (int i = 0; i < M.nRows; i++)
    {
        M.m[i] = new double[M.nCols];
        for (int j = 0; j < M.nCols; j++)
        {
            op >> M.m[i][j];
        }
    }

    return op;
}


Matrix::Matrix(std::ifstream &myFile){
    while (!myFile.eof()){
        
        //armazena em uma string a primeira linha do arquivo, que contem o numero de linhas e colunas da matriz
        std::string data; 
        getline(myFile,data);

        nRows = (int)data[0] - 48;
        nCols = (int)data[2] - 48;

        m = new double * [nRows];
        for (int i = 0; i < nRows; i++){
            m[i] = new double [nCols];
        }

        std::string aux;
            
        for( int j = 0; j < nRows; j++){
            int val = 0;
            getline(myFile, aux);
            for( int k = 0; k < nCols; k++){
                   m[j][k] = (double)aux[val] - 48.0;
                   val = val + 2;
            }
        }
    }
}*/

int main()
{
    ifstream in("myMatrix.txt");
    //Matrix Y;
    Matrix X(3, 1), A(3, 3), C(3, 3);
    Matrix Z(3, 2, 7.0);
    //Matrix W(in);

    // operadores a serem implementados em sua classe:

    A(2, 1) = 10; // altera o valor de uma posição de A
    C = A + A;    // Soma
    C.print();

    C -= A; // Subtração
    C.print();

    A = C - A; // Subtração
    A.print();

    A += A; // Soma
    A.print();

    A = ~C; // A é igual a transposta de C
    A.print();

    X *= 2; // multiplicação por uma constante
    X.print();

    C = A * X; // multiplicação de matrizes
    C.print();

    C *= X; // multiplicação de matrizes
    C.print();

    /*
    if (A == C)                // verifica a igualdade entre A e C
        if (X != Y)            // verifica a desigualdade entre A e C
            cout << Z << endl; // impressão de matrizes

    //cin >> W; // leitura de dados para dentro da matriz Y
    */

    return 0;
}
