#include "../include/ContaPoupanca.hpp"

std::map<int, bool> ContaPoupanca::usedIds;

void ContaPoupanca::saca(double valor){
if (valor > 0 && this->getSaldo()>= valor) {
        this->sacarSaldo(valor);
    }
};

void ContaPoupanca ::deposita(double valor){
    if (valor > 0) {
        this->adicionaAoSaldo(valor);
    }
};

void ContaPoupanca ::tiraExtrato() const {
    std::cout << "Extrato Conta Poupanca" << std::endl
              << "Numero da Conta: " << this->getNumeroConta() << std::endl
              << "Saldo: " << this->getSaldo() << std::endl
              << "Taxa de Rendimento: " << this->getTaxaRendimento() << std::endl;
};

int ContaPoupanca::getNextID() {
    srand(time(NULL));
    int new_id = rand() % 1000 + 1;
    while (usedIds[new_id] == true)
        new_id = rand() % 1000 + 1;
    usedIds[new_id] = true;
    return new_id;
}