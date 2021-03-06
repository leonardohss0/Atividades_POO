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

    static std::map<int, bool> usedIds;

    int getNextID();
    void setSenha(std::string newPW);

public:
    ContaBancaria(std::string pw) : numero(getNextID()), senha(pw), saldo(0){};

    void alteraSenha();

    virtual void saca(double valor) = 0;
    virtual void deposita(double valor) = 0;
    virtual void tiraExtrato() const = 0;
};

int ContaBancaria::getNextID() {
    srand(time(NULL));
    int new_id = rand() % 1000 + 1;
    while (usedIds[new_id] == true)
        new_id = rand() % 1000 + 1;
    usedIds[new_id] = true;
    return new_id;
}

void ContaBancaria::alteraSenha() {
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
            std::cout << "Senha incorreta! Tentativas restantes: " << 3 - tentativas << std::endl
        }
    }
}

void ContaBancaria::setSenha(std::string newPW) {
    this->senha = newPW;
};

#endif