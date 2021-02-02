#include "../Ponto2D/Ponto2D.hpp"

class Ponto3D : public Ponto2D {

public:
  Ponto3D(double xx = 0, double yy = 0, double zz = 0)
      : Ponto2D(xx, yy), z(zz){};
  friend std::ostream &operator<<(std::ostream &op, const Ponto3D &p);
  Ponto3D &operator=(const Ponto2D &p);
  void set(double nx = 0, double ny = 0, double nz = 0);
  inline double get_z() const { return this->z; };

private:
  double z;
};

