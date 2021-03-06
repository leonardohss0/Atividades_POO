#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include "ContaBacaria.hpp"

class ContaCorrente : public ContaBancaria {
    int quantidadeTransacoes;

public:
    ContaCorrente(std::string pw) : ContaBancaria(pw), quantidadeTransacoes(0){};

    inline int getQuantTransacoes() const { return this->quantidadeTransacoes; };

    virtual void saca(double valor) = 0;
    virtual void deposita(double valor) = 0;
    virtual void tiraExtrato() const = 0;
};

#endif