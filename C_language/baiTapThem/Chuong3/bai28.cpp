#include<iostream>
#include<time.h>
#include<cstdlib>
#include<conio.h>
using namespace std;
int leapYear(int y) {
  if (y%400==0 || y%4==0 && y%100!=0) {
    return 1;
  }
  return 0;
}
template<class Type>
int getDay(Type date){
  switch(date->tm_mon) {
    case 1:case 3:case 5:case 7:case 8:case 10: case 12: return 31;
    case 4:case 6:case 9:case 11: return 30;
    case 2:
      if (leapYear(date->tm_year)) {
        return 29;
      }else return 28;
  }
}
template<class Type>
void getTime(Type time) {
  time->tm_year+=1900;
  time->tm_mon++;
  while(1) {
    system("cls");
    if (kbhit()) { // press keyboard
      char key = _getch();
      if (key == 72) {
        time->tm_mday++;
      }else if (key == 80) {
        time->tm_mday--;
      }
    }
    if (time->tm_mday<1) {
      time->tm_mon--;
      time->tm_mday = getDay(time);
    }else if (time->tm_mday>getDay(time)) {
      time->tm_mon++;
      time->tm_mday = 1;
    }

    if (time->tm_mon>12) {
      time->tm_year++;
      time->tm_mon = 1;
    }else if (time->tm_mon<1) {
      time->tm_year--;
      time->tm_mon = 12;
    }
    cout << time->tm_mday << '/' << time->tm_mon << '/' << time->tm_year;
  }
}
int main() {
  time_t rawTime;
  struct tm *localTime;
  time(&rawTime);
  localTime = localtime(&rawTime);
  getTime(localTime);
  return 0;
}
