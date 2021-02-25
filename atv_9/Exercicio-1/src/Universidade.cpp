#include "../include/Universidade.hpp"
#include "../include/ProfHorista.hpp"
#include "../include/ProfIntegral.hpp"
#include <iostream>
#include <memory>

Universidade::Universidade(double s) : saldo(s){};

Universidade::~Universidade() {
}

void Universidade::addProfessor(std::string n, double sm) {
    this->professores.push_back(std::shared_ptr<ProfIntegral>(new ProfIntegral(n, sm)));
}

void Universidade::addProfessor(std::string n, double nht, double vh) {
    this->professores.push_back(std::shared_ptr<ProfHorista>(new ProfHorista(n, nht, vh)));
}

void Universidade::addProfessor(std::shared_ptr<Professor> t) {
    this->professores.push_back(t);
};

double Universidade::totalPago() const {
    double totalPago = 0;
    for (auto &i : professores)
        totalPago += i->getSalario();
    return totalPago;
}

void Universidade::listaProf_Salario() const {
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
              << std::endl
              << "LISTA PROF - SALARIO\n\n";
    for (auto &i : professores) {
        std::cout << i->getName() << "   " << i->getSalario() << std::endl;
    }
    std::cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
              << std::endl;
}