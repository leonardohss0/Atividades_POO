#include <iostream>
#include <memory>
#include <vector>

#include "./include/ContaCorrente.hpp"
#include "./include/ContaPoupanca.hpp"

static std::map<int, bool> usedIds;

int main() {

    int count = 0, tipo = 0, n_contas;
    std::cout << "Quantas contas gostaria de criar?" << std::endl;
    std::cin >> n_contas;

    std::vector<std::unique_ptr<ContaBancaria>> contasVec;

    while (count < n_contas) {
        std::cout << "\nEscolha o tipo de conta(1 - Corrente, 2 - Poupanca): " << std::endl;
        std::cin >> tipo;

        std::string pw = "";

        if (tipo == 1 || tipo == 2) {
            std::cout << "Digite a senha para a conta: " << std::endl;
            std::cin >> pw;
        }

        if (tipo == 1) {
            contasVec.push_back(std::unique_ptr<ContaCorrente>(new ContaCorrente(pw)));
            count++;
        } else if (tipo == 2) {
            contasVec.push_back(std::unique_ptr<ContaPoupanca>(new ContaPoupanca(pw)));
            count++;
        } else {
            std::cout << "Escolha do tipo de conta invalida" << std::endl;
        }
    }

    std::cout << "\nTaxa de Rendimento das Contas Poupanca: 2.5%\n\n" << std::endl;

    for (int index = 0; index < contasVec.size(); ++index) {
        contasVec[index]->deposita(100 + contasVec[index]->getNumeroConta());
        contasVec[index]->saca(50);
    }

    for (int index = 0; index < contasVec.size(); ++index) {
        contasVec[index]->tiraExtrato();
        std::cout << std::endl;
    }

}
