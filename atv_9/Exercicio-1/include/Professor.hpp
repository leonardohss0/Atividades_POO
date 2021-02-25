#ifndef PROF_ABS_H
#define PROF_ABS_H

#include <string>

class Professor {
    std::string nome;

public:
    Professor(std::string n);
    std::string getName() const;
    virtual double getSalario() = 0;
    virtual ~Professor();
};

#endif