#ifndef __MATRIX_H
#define __MATRIX_H

#include <fstream>

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix(int rows = 0, int cols = 0, const double &value = 0.0);
        Matrix(std::ifstream& myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        inline int getRows() const { return this->nRows; }
        inline int getCols() const { return this->nCols; }
        double get(int row, int col) const;   
        double getZeroBased(int row, int col) const;
        
        // overloaded operators
        double& operator() (int i, int j);
        Matrix operator+ (const Matrix& C) const;
        Matrix operator* (const Matrix& A) const;
        Matrix operator- (const Matrix& A) const;
        bool operator== (const Matrix& A) const;
        bool operator!= (const Matrix& A) const;
        void operator= (const Matrix& A);
        void operator-= (const Matrix& A);
        void operator+= (const Matrix& A);
        void operator*= (int n);
        void operator*= (Matrix &A);
        Matrix operator~ () const;
        void setZeroBased(int row, int col, double value);
        friend std::ostream &operator<< (std::ostream &output, const Matrix &A); 
        friend std::istream &operator>> (std::istream &input, Matrix &A); 

        // other methods
        void print() const;
        void unit();
        void zeros();
        void ones();
           
};

#endif
