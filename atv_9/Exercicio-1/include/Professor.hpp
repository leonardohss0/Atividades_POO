#ifndef PROF_ABS_H
#define PROF_ABS_H

#include <string>

class Professor {
    std::string nome;

public:
    Professor(std::string n) : nome(n){};
    std::string getName() const { return this->nome; };
    virtual double getSalario() const = 0;
    virtual ~Professor(){};
};

#endif