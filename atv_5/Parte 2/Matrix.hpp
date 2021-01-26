#include <iostream>

using namespace std;

class Matrix
{
private:
    double **m; // m é um array 2D a ser implementado como um pointer de pointers
    int nRows;  // numero de linhas
    int nCols;  //  numero de colunas

public:
    Matrix(int rows = 0, int cols = 0, const double &value = 0.0);
    Matrix(const Matrix &M);
    Matrix(ifstream &myFile);
    ~Matrix();

    // basic getters
    inline int getRows() const { return this->nRows; };
    inline int getCols() const { return this->nCols; };
    double get(int row, int col) const;
    double getZeroBased(int row, int col) const;

    // setters
    void setValue(int row, int column, double value);

    void print() const;

    //Operadores
    double &operator()(int i, int j) const;

    Matrix &operator+(const Matrix &M) const;
    Matrix &operator+=(const Matrix &M);
    Matrix &operator-(const Matrix &M) const;
    Matrix &operator-=(const Matrix &M);
    Matrix operator*(const Matrix &M) const;
    Matrix &operator*=(const Matrix &M);
    Matrix &operator*=(int value);
    Matrix operator=(const Matrix &M);
    Matrix &operator~() const;
    bool operator==(const Matrix &M) const;
    bool operator!=(const Matrix &M) const;

    friend istream &operator>>(istream &op, Matrix &M);
    friend ostream &operator<< (std::ostream &output, const Matrix &A);
};