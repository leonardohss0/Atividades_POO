#include <iostream>
#include <ctime>
#include "./headers/Agenda.hpp"

int main()
{
  int number;
  srand(time(NULL));

  std::cout << "Hi Alexa, please, add some contacts to my agenda" << std::endl;
  std::cout << "Sure Luiz, please, tell me, how many people do you want to add?" << std::endl;
  std::cin >> number;
  fflush(stdin);
  
  Agenda a(number);
  
  std::cout << "Numero de amigos na lista: " << a.contaAmigos() << std::endl;
  std::cout << "Numero de conhecidos na lista: " << a.contaConhecidos() << std::endl;

  a.addInformacoes();

  a.imprimeAniversarios();
  a.imprimeEmail();

  return 0;
}