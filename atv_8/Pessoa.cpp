#include <iostream>
#include "./headers/Pessoa.hpp"

Pessoa::Pessoa(const std::string user_name, int user_age, std::string user_birthday, std::string user_email) : name(user_name), age(user_age), birthday(user_birthday), email(user_email) {}

void Pessoa::print(void) const{
  std::cout << "Name: " << getName() << std::endl;
  std::cout << "Age: " << getAge() << std::endl;
  std::cout << "Email: " << getEmail() << std::endl;
  std::cout << "Aniversario: " << getBirthday() << std::endl;
}
