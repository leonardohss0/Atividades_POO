#ifndef SENOIDE_H
#define SENOIDE_H

#include "Funcao.hpp"

class Senoide : public Funcao {
public:
    Senoide(){};
    ~Senoide(){};
    double func(double input) override;
};

#endif
