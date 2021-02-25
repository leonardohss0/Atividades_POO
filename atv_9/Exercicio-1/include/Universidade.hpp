#include "Professor.hpp"
#include <vector>

using std::vector;

class Universidade {
private:
    vector<Professor *> professores;
    double saldo;

public:
    Universidade(double s = 0);
    void addProfessor(std::string n, double sm = 0);
    void addProfessor(std::string n, double nht = 0, double vh = 0);
    double totalPago() const;
    void listaProf_Salario() const;
};