#include <iostream>

long fib(int num) {
  long previous = 1;
  long result = 1;
  long temp = 0;
  for (int i = 1; i < num; ++i) {
    temp = previous;
    previous = result;
    result = temp + result;
  }
  return result;
}

int main() {

  std::cout << "Insira o indice(inicia em 0) do numero desejado da seq. de "
               "fibonacci: "
            << std::endl;

  int num;
  std::cin >> num;

  std::cout << fib(num) << std::endl;

  return 0;
}
