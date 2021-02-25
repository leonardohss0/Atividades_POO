#include "Professor.hpp"
#include <vector>

using std::vector;

class Universidade {
private:
    vector<Professor *> professores;
    double saldo;

public:
    Universidade(double s = 0);
    ~Universidade();
    void addProfessor(std::string n, double sm);
    void addProfessor(std::string n, double nht, double vh);
    void addProfessor(Professor *t);
    double totalPago() const;
    void listaProf_Salario() const;
};