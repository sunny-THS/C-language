#include "Composition.h"

#define YEAR_NOW 2020 // nam hien tai
// init 
Birthday::Birthday(int d, int m, int y)
:day(d), month(m), year(y){}
Person::Person(string n, Birthday date)
:name(n), d(date){}

void Birthday::printDate() {
  cout<<day<<"/"<<month<<"/"<<year<<endl;
}

int Birthday::proccessAge(int y) {
  return YEAR_NOW-y;
}

void Person::printInfo() {
  cout<<name<<endl;
  d.printDate();
  cout<<d.proccessAge(d.year);
}

int main() {
  Birthday bd(5, 2, 2001);
  Person p("Tu Hue Son", bd);
  p.printInfo();

  return 0;
}
