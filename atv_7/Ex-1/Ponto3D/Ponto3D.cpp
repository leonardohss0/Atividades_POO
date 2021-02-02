#include "Ponto3D.hpp"

Ponto3D &Ponto3D::operator=(const Ponto2D &p) {
  this->x = p.get_x();
  this->y = p.get_y();
  return *this;
}

void Ponto3D::set(double xx, double yy, double zz) {
  this->x = xx;
  this->y = yy;
  this->z = zz;
}

std::ostream &operator<<(std::ostream &op, const Ponto3D &p) {
  op << std::endl;
  op << "x = " << p.get_x() << std::endl;
  op << "y = " << p.get_y() << std::endl;
  op << "z = " << p.get_z() << std::endl;
  return op;
}