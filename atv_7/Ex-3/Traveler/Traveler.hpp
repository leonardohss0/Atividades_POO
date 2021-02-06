#include <string>

class Traveler {
  std::string s;

  public:
    Traveler(std::string x);
    std::string getS() const;
    void operator= (const Traveler &A);
  
  friend class BusinessTraveler;
};