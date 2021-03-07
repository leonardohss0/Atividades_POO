#include "../include/ContaCorrente.hpp"

int ContaCorrente::lastID = 1;

void ContaCorrente::saca(double valor) {
    if (valor > 0 && this->getSaldo() >= valor) {
        this->sacarSaldo(valor);
        this->quantidadeTransacoes++;
    }
}
void ContaCorrente::deposita(double valor) {
    if (valor > 0) {
        this->adicionaAoSaldo(valor);
        this->quantidadeTransacoes++;
    }
}
void ContaCorrente::tiraExtrato() const {
    std::cout << "Extrato Conta Corrente" << std::endl
              << "Numero da Conta: " << this->getNumeroConta() << std::endl
              << "Saldo: " << this->getSaldo() << std::endl
              << "Quantidade de Transacoes: " << this->getQuantTransacoes() << std::endl;
}
