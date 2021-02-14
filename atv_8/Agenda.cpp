#include <iostream>
#include "./headers/Agenda.hpp"
#include<cstdlib>
#include<ctime>
#include <algorithm>

int generateRandomNumber() {
  double r = ((double) rand() / (RAND_MAX)); 
  return r >= 0.5 ?  2 : 1;
}

Agenda::Agenda(int number) : num(number) {
  for(int i = 0; i < number; ++i) {
    int t = generateRandomNumber();
    tipo.push_back(t);
    if (t == 1) p.push_back(Amigo());
    else if (t == 2) p.push_back(Conhecido());
  }
}

void Agenda::addInformacoes() {
  for (int i = 0; i < this->num; ++i) {
    if (tipo[i] == 1) {
      std::string usr, bday;
      int idade;
      std::cout << "\n*** *** ***\nAdicione informacoes para um amigo:\n"
        << "Nome: ";
      std::cin >> usr; std::cout << std::endl;
      std::cout << "Idade: "; std::cin >> idade; std::cout << std::endl;
      std::cout << "Aniversario: "; std::cin >> bday; std::cout << std::endl;
      p[i] = Amigo(usr, idade, bday);
      std::cout << "Contato adicionado com sucesso!" << std::endl;
    }
    else {
      std::string usr, mail;
      int idade;
      std::cout << "\n*** *** ***\nAdicione informacoes para um conhecido:\n"
        << "Nome: ";
      std::cin >> usr; std::cout << std::endl;
      std::cout << "Idade: "; std::cin >> idade; std::cout << std::endl;
      std::cout << "Email: "; std::cin >> mail; std::cout << std::endl;
      p[i] = Conhecido(usr, idade, mail);
      std::cout << "Contato adicionado com sucesso!" << std::endl;
    }
  }
}

void Agenda::imprimeAniversarios() const {
  std::cout << "\nTodos os aniversarios na agenda: " << std::endl;
  std::cout << std::endl << "Nome\t|||\t Aniversario" << std::endl;
  for (int i = 0; i < this->num; ++i) {
    if (tipo[i] == 1) {
      std::cout << this->p[i].getName() << "\t   \t" << this->p[i].getBirthday() << std::endl;
    }
  }
}

void Agenda::imprimeEmail() const {
  std::cout << "\nTodos os emails na agenda: " << std::endl;
  std::cout << std::endl << "Nome\t|||\t Email" << std::endl;
  for (int i = 0; i < this->num; ++i) {
    if (tipo[i] == 2) {
      std::cout << this->p[i].getName() << "\t   \t" << this->p[i].getEmail() << std::endl;
    }
  }
}

int Agenda::contaAmigos() const {
  return std::count(tipo.begin(), tipo.end(), 1);
}

int Agenda::contaConhecidos() const {
  return std::count(tipo.begin(), tipo.end(), 2);
}