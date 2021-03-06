#ifndef CONTA_POUP_H
#define CONTA_POUP_H

#include "ContaBacaria.hpp"

class ContaPoupanca : ContaBancaria {
    double taxaRendimento;

public:
    ContaPoupanca(std::string pw, double taxa = 2.5) : ContaBancaria(pw), taxaRendimento(taxa){};

    inline double getTaxaRendimento() const { return this->taxaRendimento; }

    virtual void saca(double valor);
    virtual void deposita(double valor);
    virtual void tiraExtrato() const;
};

#endif