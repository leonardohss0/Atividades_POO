#include <iostream>
#include "agenda.hpp"

Pessoa::Pessoa(){
    *this->name = "indefinido";
    this->age = 0;
}

Pessoa::Pessoa(const std::string& user_name, int user_age){
    *this->name = user_name;
    this-> age = user_age;

}

void Pessoa::print(void) const{

    std::cout << "Name: " << getName() <<" "<< std::endl;
    std::cout << "Age: " << getAge() <<" "<< std::endl;

}

void Amigo::print(void) const{

    std::cout << "Name: " << getName() <<" "<< std::endl;
    std::cout << "Age: " << getAge() <<" "<< std::endl;
    std::cout << "Birth Date: " << std::endl;

}

void Known::print(void) const{

    std::cout << "Name: " << getName() <<" "<< std::endl;
    std::cout << "Age: " << getAge() <<" "<< std::endl;
    std::cout << "Email: " << getEmail() <<" "<< std::endl;

}
