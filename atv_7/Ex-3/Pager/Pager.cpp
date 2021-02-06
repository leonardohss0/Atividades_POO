#include "Pager.hpp"

Pager::Pager(std::string str) : s(str) {};

std::string Pager::getS() const { return this->s; }

void Pager::operator= (const Pager &A) {
  this->s = A.getS();
}