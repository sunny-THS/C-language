#include <iostream>
using namespace std;
class Enemy {
  public:
    virtual void attack() {
      cout << "Enemy" << endl;
    }
};
class Monster : public Enemy {
  public:
    void attack() {
      cout << "Monster" << endl;
    }
};
class Ninja : public Enemy {
  public:
    void attack() {
      cout << "Ninja" << endl;
    }
};

int main() {
  Enemy *monster = new Monster;
  Enemy *ninja = new Ninja;
  Enemy enemy;

  monster->attack();
  ninja->attack();
  enemy.attack();
  return 0;
}
