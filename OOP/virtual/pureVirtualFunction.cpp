#include <iostream>
using namespace std;
class Enemy {
  public:
    virtual void attack() = 0; // this is pure virtual function
};
class Ninja : public Enemy {
  public:
    void attack() {
      cout << "Ninja" << endl;
    }
};
class Monster : public Enemy {
  public:
    void attack() {
      cout << "Monster" << endl;
    }
};
int main() {
  Enemy *ninja = new Ninja;
  Enemy *monster = new Monster;
  // Enemy enemy; // error

  ninja->attack();
  monster->attack();
  return 0;
}
