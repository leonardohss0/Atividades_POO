#include "./BusinessTraveler/BusinessTraveler.hpp"
#include <iostream>

int main() {
  BusinessTraveler t;
  std::cout << t.getPager().getS() << std::endl;
  std::cout << t.getS() << std::endl;
}