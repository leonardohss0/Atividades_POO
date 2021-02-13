#include <string>

const int MAX=100;

class Pessoa{
    private:
    std::string name[MAX];
    int age;

    protected:

    public:
    Pessoa();
    Pessoa(const std::string& user_name, int user_age);

    virtual inline int getAge(void) const {return this->age; };
    virtual inline std::string getName(void) const {return *this->name; };

    inline void setAge(int user_age) { this-> age = user_age; };
    inline void setName(std::string user_name) { *this->name = user_name; };

    virtual void print(void) const;

};

class Amigo : public Pessoa {

    private:
       //birth_date 

    protected:

    public:
        Amigo(){
            this->getName() = "indefinido";
            //this->getAge() = 0;

        };

        Amigo(std::string& user_name, int user_age){
            user_name = this->getName();
            user_age = this->getAge();
        }

        inline int getAge(void) const override {return this-> getAge(); };

        inline std::string getName(void) const override{return this-> getName(); };

        void print(void) const override;


};

class Known : public Pessoa {
    
    private:
       std::string email[MAX];

    protected:

    public:
        Known(){
            this->getName() = "indefinido";
            //this->getAge() = 0;
            *this->email = "indefinido";

        };

        Known(std::string& user_name, int user_age, std::string user_email){
            user_name = this->getName();
            user_age = this->getAge();
            user_email = *email;

        }

        virtual inline std::string getEmail(void) const {return *this->email; };

        inline int getAge(void) const override {return this-> getAge(); };
        inline std::string getName(void) const override{return this-> getName(); };

        inline void setEmail(std::string user_email) { *this->email = user_email; };

        void print(void) const override;

};