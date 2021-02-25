#include "../include/Universidade.hpp"
#include "../include/ProfHorista.hpp"
#include "../include/ProfIntegral.hpp"
#include <iostream>

Universidade::Universidade(double s) : saldo(s){};

void Universidade::addProfessor(std::string n, double sm) {
    this->professores.push_back(new ProfIntegral(n, sm));
}

void Universidade::addProfessor(std::string n, double nht = 0, double vh = 0) {
    this->professores.push_back(new ProfHorista(n, nht, vh));
}

double Universidade::totalPago() const {
    double totalPago = 0;
    for (auto &i : professores)
        totalPago += i->getSalario();
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*"
              << "TOTAL MENSAL PAGO AOS PROFESSORES: " << totalPago
              << "*-*-*-*-*-*-*-*-*-*-*-*-*-*"
              << std::endl;
}

void Universidade::listaProf_Salario() const {
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl
              << "LISTA Professor - Salario" << std::endl;
    for (auto &i : professores) {
        std::cout << i->getName() << "   " << i->getSalario() << std::endl;
    }
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}