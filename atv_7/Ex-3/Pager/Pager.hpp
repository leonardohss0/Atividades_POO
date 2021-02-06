#include <string>

class Pager {
  std::string s;

  public:
    Pager(std::string x);
    std::string getS() const;
    void operator= (const Pager &A);
};