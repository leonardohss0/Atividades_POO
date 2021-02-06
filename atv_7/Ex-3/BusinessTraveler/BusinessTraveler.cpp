#include "./BusinessTraveler.hpp"

BusinessTraveler::BusinessTraveler(std::string str) :
    Traveler(str), p(str) {};
    

BusinessTraveler::BusinessTraveler(BusinessTraveler &x) : Traveler(x.getS()),
  p(x.getS()) {}

Pager BusinessTraveler::getPager() const {
  return this->p;
} 

void BusinessTraveler::operator= (const BusinessTraveler &A) {
  this->s = A.getS();
  this->p = A.getPager();
};
