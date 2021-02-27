#ifndef SENOIDE_H
#define SENOIDE_H

#include "Funcao.hpp"

class Senoide : public Funcao {
    private:
        int a, b, c;

    public:
        Senoide(int a, int b, int c) : a(a), b(b), c(c) { };
        double func(double input) override;
};

#endif
