#include <fstream>
#include <iostream>
#include "Matrix.hpp"


int main()
{
    std::ifstream in("matrix.txt");
    Matrix Y;
    Matrix X(3, 1, 3), A(3, 3, 1), C(3, 3, 1);
    Matrix Z(3, 2, 7.0);
    Matrix W(in);

    A(2,1) = 10;  
    C = A + A;
    C -= A;       
    A = C - A;     
    A += A;
    A = ~C;
    X *= 2;
    C = A*Z;
    A *= Z;

    if (A == C) std::cout << "A == C" << std::endl;
    if(X != Y) std::cout << "X != Y" << std::endl;

    std::cout << "\nMatriz Z: " << std::endl << Z << std::endl; 
    std::cout << "Insira valores para a matriz W(Ctrl+D para parar): " << std::endl;
    std::cin >> W;                 
 
    return 0;
}