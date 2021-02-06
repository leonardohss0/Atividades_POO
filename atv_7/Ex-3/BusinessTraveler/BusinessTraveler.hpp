#include "../Pager/Pager.hpp"
#include "../Traveler/Traveler.hpp"

class BusinessTraveler : public Traveler {
  Pager p;

  public:
    BusinessTraveler(std::string x="1");
    BusinessTraveler(BusinessTraveler &x);
    void operator= (const BusinessTraveler &A);
    Pager getPager() const;
};