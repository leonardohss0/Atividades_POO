#include <fstream>
#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main()
{
    ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1), A(3,3), C(3,3);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    // operadores a serem implementados em sua classe:
    
    A(2,1) = 10;                               // altera o valor de uma posição de A
    C = A + A;                                  // Soma
    C -= A;                                     // Subtração       
    A = C - A;                                  // Subtração
    A += A;                                   // Soma
    A = ~C;                                  // A é igual a transposta de C
    X *= 2;                                   // multiplicação por uma constante
    C = A*X;                                         // multiplicação de matrizes
    C *= X;                                            // multiplicação de matrizes
    if (A == C)                                 // verifica a igualdade entre A e C
    if(X != Y)                                  // verifica a desigualdade entre A e C
    cout << Z << endl;                        // impressão de matrizes
    cin >> W;                                     // leitura de dados para dentro da matriz Y 
  
    return 0;
}

