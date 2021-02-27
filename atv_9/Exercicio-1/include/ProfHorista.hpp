#ifndef PROF_HORISTA_H
#define PROF_HORISTA_H

#include "Professor.hpp"
#include <string>

class ProfHorista : public Professor {
    double nrNorasTrabalhadas;
    double valorHora;

public:
    ProfHorista(std::string n, double nht=0, double vh=0);
    double getSalario() const override;
    virtual ~ProfHorista(){};
};

#endif