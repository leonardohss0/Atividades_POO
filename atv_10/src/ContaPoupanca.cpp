#include "../include/ContaPoupanca.hpp"

int ContaPoupanca::lastID = 1;

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
