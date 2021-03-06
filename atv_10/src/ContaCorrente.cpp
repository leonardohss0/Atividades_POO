#include "../include/ContaCorrente.hpp"

std::map<int, bool> ContaPoupanca::usedIds;

void ContaCorrente::saca(double valor) {

    this->sacarSaldo(valor);
}
void ContaCorrente::deposita(double valor) {
    if (valor > 0) {
        this->adicionaAoSaldo(valor);
    }
}
void ContaCorrente::tiraExtrato() const {
    std::cout << "Extrato Conta Corrente" << std::endl
              << "Numero da Conta: " << this->getNumeroConta() << std::endl
              << "Saldo: " << this->getSaldo() << std::endl
              << "Quantidade de Transacoes: " << this->getQuantTransacoes() << std::endl;
}

int ContaCorrente::getNextID() {
    srand(time(NULL));
    int new_id = rand() % 1000 + 1;
    while (usedIds[new_id] == true)
        new_id = rand() % 1000 + 1;
    usedIds[new_id] = true;
    return new_id;
}
