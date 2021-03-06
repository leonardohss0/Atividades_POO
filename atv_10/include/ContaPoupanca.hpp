#ifndef CONTA_POUP_H
#define CONTA_POUP_H

#include "ContaBancaria.hpp"

class ContaPoupanca : public ContaBancaria {
    double taxaRendimento;
    static int lastID;

public:
    ContaPoupanca(std::string pw, double taxa = 2.5) : ContaBancaria(pw, this->lastID++), taxaRendimento(taxa){};
    virtual ~ContaPoupanca(){};

    inline double getTaxaRendimento() const { return this->taxaRendimento; }

    void saca(double valor) override;
    void deposita(double valor) override;
    void tiraExtrato() const override;
};

#endif