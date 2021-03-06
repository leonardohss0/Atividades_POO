#ifndef CONTA_POUP_H
#define CONTA_POUP_H

#include "ContaBancaria.hpp"

class ContaPoupanca : public ContaBancaria {
    double taxaRendimento;

    static std::map<int, bool> usedIds;

    int getNextID();

public:
    ContaPoupanca(std::string pw, double taxa = 2.5) : ContaBancaria(pw, this->getNextID()), taxaRendimento(taxa){};
    virtual ~ContaPoupanca(){};

    inline double getTaxaRendimento() const { return this->taxaRendimento; }

    void saca(double valor) override;
    void deposita(double valor) override;
    void tiraExtrato() const override;
};

#endif