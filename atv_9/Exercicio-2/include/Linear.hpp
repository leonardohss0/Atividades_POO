#ifndef LINEAR_H
#define LINEAR_H

#include "Funcao.hpp"

class Linear : public Funcao {
    int a, b;

public:
    Linear(int aa, int bb) : a(aa), b(bb){};
    ~Linear();
    double func(double input) override;
};

#endif