#include "Ponto.hpp"

Ponto &Ponto::operator--() {
  Ponto temp = *this;

  this->x = --x;
  this->y = --y;

  return *this;
}

Ponto Ponto::operator+(const Ponto &P) const {
  Ponto temp = *this;

  temp.x = this->x + P.x;
  temp.y = this->y + P.y;

  return temp;
}

int main() {

  Ponto a(1, 4), b(3, 2), c;
  c = a + b; // soma as coordenadas dos pontos a e b
  --c;       // decrementa em uma unidade as coordenadas de c

  c.print();
}
