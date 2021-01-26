#include <iostream>

class Ponto {

  int x, y;

public:
  Ponto(int xx = 0, int yy = 0) : x(xx), y(yy){};
  Ponto &operator--();
  Ponto operator+(const Ponto &P) const;
  ~Ponto(){};

  inline int getX() { return this->x; }
  inline int getY() { return this->y; }

  inline void print() { std::cout << this->x << " " << this->y << std::endl; };
};
