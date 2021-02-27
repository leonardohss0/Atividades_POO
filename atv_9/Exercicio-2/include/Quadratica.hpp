#ifndef QUADRATICA_H
#define QUADRATICA_H

#include "Funcao.hpp"

class Quadratica : public Funcao {
    int a, b, c;

    public:
        Quadratica(int a, int b, int c) : a(a), b(b), c(c) { } ;
        double func(double input) override;
};

#endif