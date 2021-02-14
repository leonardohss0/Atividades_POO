#include <string>

class Pessoa {
private:
  std::string name, birthday, email;
  int age;

public:
  Pessoa(std::string user_name = "indefinido", int user_age = 0, std::string user_birthday="", std::string user_email="");

  inline int getAge() const { return this->age; };
  inline std::string getName() const { return this->name; };

  inline void setAge(int user_age) { this->age = user_age; };
  inline void setName(std::string user_name) { this->name = user_name; };

  virtual inline std::string getBirthday() const { return this->birthday; }
  inline std::string getEmail() const { return this->email; };
  virtual void print() const;
};

class Amigo : public Pessoa {

public:
  Amigo(std::string user_name = "indefinido", int user_age = 0,
        std::string bday = "indefinido", std::string mail="");

  void print() const override;
};

class Conhecido : public Pessoa {

public:
  Conhecido(std::string user_name = "indefinido", int user_age = 0,
            std::string user_mail = "indefinido", std::string user_birthday="");

  void print() const override;
};