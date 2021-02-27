#ifndef LINEAR_H
#define LINEAR_H

#include "Funcao.hpp"

class Linear : public Funcao {
    int a, b;

    public:
        Linear(int a, int b) : a(a), b(b) { };
        double func(double input) override;
};

#endif