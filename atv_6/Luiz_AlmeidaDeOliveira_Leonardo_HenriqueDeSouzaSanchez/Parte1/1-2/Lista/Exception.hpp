#ifndef EXCEPT_H
#define EXCEPT_H

#include <string>

class Exception {
  std::string error;

public:
  Exception(std::string s) : error(s){};
  std::string getError() { return this->error; };
};
#endif