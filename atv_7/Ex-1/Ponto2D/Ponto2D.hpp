#include <iostream>

class Ponto2D {

public:
  Ponto2D(int xx = 0.0, int yy = 0.0) : x(xx), y(yy){};
  friend std::ostream &operator<<(std::ostream &op, const Ponto2D &p);
  Ponto2D &operator=(const Ponto2D &p);
  ~Ponto2D(){};
  double get_x(void) const { return x; }
  double get_y(void) const { return y; }
  void set(double nx, double ny) {
    x = nx;
    y = ny;
  }
  friend class Ponto3D;

private:
  double x;
  double y;
};
