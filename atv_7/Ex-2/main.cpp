#include "./Box/Box.hpp"

int main() {
  Ponto3D p1, p2(0, 0, 3), p3(3, 0, 0), p4(0, 4, 0),
          p5(3, 0, 3), p6(3, 4, 3), p7(3, 4, 0), p8(0, 4, 3);

  Box a(p1, p3, p4, p2);
  Box b(3, 4, 3);

  std::cout << "Volume de a: " << a.Volume() << std::endl;
  std::cout << "Area de a: " << a.Area() << std::endl;

  std::cout << "Volume de b: " << b.Volume() << std::endl;
  std::cout << "Area de b: " << b.Area() << std::endl;

  return 0;
}

