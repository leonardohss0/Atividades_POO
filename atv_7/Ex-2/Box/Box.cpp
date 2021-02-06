#include "Box.hpp"


Box::Box(float l, float p, float h) 
    : largura(l), profundidade(p), altura(h){}

Box::Box(Ponto3D &P1, Ponto3D &P2, Ponto3D &P3, Ponto3D &P4){
  this->altura = std::abs(P1.get_z() - P4.get_z());
  this->largura = std::abs(P1.get_x() - P2.get_x());
  this->profundidade = std::abs(P1.get_y() - P3.get_y());
}
        
float Box::Area() const {
  float areaBase, areaLateral;

  areaBase = this->largura * this->profundidade;
  areaLateral = this->profundidade * this->altura;

  return  2 * areaBase + 4 * areaLateral;
}

float Box::Volume() const {
  return this->altura * this->largura * this->profundidade;
}
