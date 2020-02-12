#ifndef COMPOSITION_H
#define COMPOSITION_H
#include<string>
#include<iostream>
using namespace std;

class Birthday {
  private:
    int day, month;
  public:
    int year;
    Birthday(int d, int m, int y);
    void printDate();
    int proccessAge(int y);
};

class Person {
  public:
    Person(string n, Birthday d);
    void printInfo();
  private:
    string name;
    Birthday d;
};
#endif
