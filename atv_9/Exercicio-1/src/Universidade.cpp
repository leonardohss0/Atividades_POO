#include "../include/Universidade.hpp"
#include "../include/ProfHorista.hpp"
#include "../include/ProfIntegral.hpp"
#include <iostream>

Universidade::Universidade(double s) : saldo(s){};

Universidade::~Universidade() {
    for (int i = 0; i < professores.size(); ++i) {
        Professor *temp = professores[i];
        delete temp;
    }
}

void Universidade::addProfessor(std::string n, double sm) {
    this->professores.push_back(new ProfIntegral(n, sm));
}

void Universidade::addProfessor(std::string n, double nht, double vh) {
    this->professores.push_back(new ProfHorista(n, nht, vh));
}

double Universidade::totalPago() const {
    double totalPago = 0;
    for (auto &i : professores)
        totalPago += i->getSalario();
    return totalPago;
}

void Universidade::listaProf_Salario() const {
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << std::endl
              << "LISTA PROF - SALARIO\n\n";
    for (auto &i : professores) {
        std::cout << i->getName() << "   " << i->getSalario() << std::endl;
    }
    std::cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << std::endl;
}