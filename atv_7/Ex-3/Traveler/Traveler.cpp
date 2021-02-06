#include "Traveler.hpp"

Traveler::Traveler(std::string str) : s(str) {};

std::string Traveler::getS() const { return this->s; }

void Traveler::operator= (const Traveler &A) {
  this->s = A.getS();
}