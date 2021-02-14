#include "Pessoa.hpp"
#include <iostream>
#include <vector>

class Agenda : public Pessoa {
  private:
  std::vector<Pessoa> p;
  std::vector<int> tipo;
  int num;

  protected:

  public:
  Agenda(int number);

  void imprimeAniversarios() const;
  void imprimeEmail() const;
  void addInformacoes();
  int contaAmigos() const;
  int contaConhecidos() const;
};

