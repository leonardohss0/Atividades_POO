#ifndef QUADRATICA_H
#define QUADRATICA_H

#include "Funcao.hpp"

class Quadratica : public Funcao {
    int a, b, c;

public:
    Quadratica(int aa, int bb, int cc) : a(aa), b(bb), c(cc){};
    ~Quadratica(){};
    double func(double input) override;
};

#endif