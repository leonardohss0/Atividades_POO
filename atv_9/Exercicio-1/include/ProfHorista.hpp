#ifndef PROF_HORISTA_H
#define PROF_HORISTA_H

#include "Professor.hpp"
#include <string>

class ProfHorista : public Professor {
    double nrNorasTrabalhadas;
    double valorHora;

public:
    ProfHorista(std::string n, double nht, double vh);
    double getSalario() const;
    virtual ~ProfHorista() {};
};

#endif