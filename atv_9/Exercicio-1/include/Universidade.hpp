#include "Professor.hpp"
#include <vector>
#include <memory>

using std::vector;

class Universidade {
private:
    vector<std::shared_ptr<Professor>> professores;
    double saldo;

public:
    Universidade(double s = 0);
    ~Universidade();
    void addProfessor(std::string n, double sm);
    void addProfessor(std::string n, double nht, double vh);
    void addProfessor(std::shared_ptr<Professor> t);
    double totalPago() const;
    void listaProf_Salario() const;
};