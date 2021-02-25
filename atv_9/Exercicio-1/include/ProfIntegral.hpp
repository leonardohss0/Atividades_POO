#ifndef PROF_INTEGRAL_H
#define PROF_INTEGRAL_H

#include "Professor.hpp"
#include <string>

class ProfIntegral : public Professor {
    double salarioMensal;

public:
    ProfIntegral(std::string n, double sm);
    double getSalario() const override;
    virtual ~ProfIntegral() {};
};

#endif