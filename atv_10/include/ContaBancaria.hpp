#ifndef CONTA_ABS_H
#define CONTA_ABS_H

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

class ContaBancaria {
    std::string senha;
    int numero;
    double saldo;

protected:
    void setSenha(std::string newPW) {
        this->senha = newPW;
    };
    
    void sacarSaldo(double valor) {
        if (valor > 0 && this->getSaldo() >= valor) {
            this->saldo -= valor;
        }
    };
    void adicionaAoSaldo(double addS) { this->saldo += addS; };

public:
    ContaBancaria(std::string pw, int conta) : senha(pw), numero(conta), saldo(0){};
    virtual ~ContaBancaria(){};

    void alteraSenha() {
        std::cout << "***ALTERANDO SENHA***" << std::endl
                  << "Digite a senha antiga para prosseguir: " << std::endl;

        std::string typedPW = "";
        int tentativas = 0;
        std::cin >> typedPW;

        while (tentativas < 3) {
            if (typedPW == this->senha) {
                std::cout << "Senha correta\nDigite a nova senha: " << std::endl;
                std::cin >> typedPW;
                this->setSenha(typedPW);
                std::cout << "Senha atualizada com sucesso!" << std::endl;
            } else {
                tentativas++;
                std::cout << "Senha incorreta! Tentativas restantes: " << 3 - tentativas << std::endl;
            }
        }
    };

    virtual void saca(double valor) = 0;
    virtual void deposita(double valor) = 0;
    virtual void tiraExtrato() const = 0;

    inline int getNumeroConta() const { return this->numero; }
    inline double getSaldo() const { return this->saldo; }
};

#endif