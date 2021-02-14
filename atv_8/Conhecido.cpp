#include <iostream>
#include "./headers/Pessoa.hpp"

Conhecido::Conhecido(const std::string user_name, int user_age, std::string user_mail, std::string user_birthday) 
      : Pessoa(user_name, user_age, user_birthday, user_mail) {}

void Conhecido::print() const {
  std::cout << "\n***Contato Conhecido ***\n" << std::endl;
  std::cout << "Name: " << getName() << " " << std::endl;
  std::cout << "Age: " << getAge() << " " << std::endl;
  std::cout << "Email: " << getEmail() << " " << std::endl;
}
