#include <iostream>
#include "./headers/Pessoa.hpp"

Amigo::Amigo(const std::string user_name, int user_age, std::string bday, std::string mail)
      : Pessoa(user_name, user_age, bday, mail) {};

void Amigo::print() const {
  std::cout << "\n***Contato Amigo ***\n" << std::endl;
  std::cout << "Name: " << this->getName() <<" "<< std::endl;
  std::cout << "Age: " << this->getAge() <<" "<< std::endl;
  std::cout << "Birth Date: " << this->getBirthday() <<" "<< std::endl;
}
