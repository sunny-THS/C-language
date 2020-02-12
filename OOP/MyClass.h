#ifndef MyClass_H
#define MyClass_H
#include<string>

class myClass {
  public:
    void setInfo(std::string n, std::string c, std::string a){
      name = n;
      country = c;
      age = a;
    }
    void getInfo() {
      std::cout << "================" << std::endl;
      std::cout << "Ten: " + name << std::endl;
      std::cout << "Quoc Gia: " + country << std::endl;
      std::cout << "Tuoi: " + age << std::endl;
    }
  private:
    std::string name, country, age;
};

#endif
