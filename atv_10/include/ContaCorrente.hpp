#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include "ContaBancaria.hpp"

class ContaCorrente : public ContaBancaria {
    int quantidadeTransacoes;
    static int lastID;

public:
    ContaCorrente(std::string pw) : ContaBancaria(pw, this->lastID++), quantidadeTransacoes(0){};
    virtual ~ContaCorrente() {};

    inline int getQuantTransacoes() const { return this->quantidadeTransacoes; };

    void saca(double valor) override;
    void deposita(double valor) override;
    void tiraExtrato() const;
};

#endif