// STT: 29
// MSSV: 2001190791
// Ho va Ten: Tu Hue Son
// Noi Dung: Bai tap ve nha buoi 2
// ----------------------------------------
// khai bao thu vien
#include <stdio.h>
#include <conio.h>
#include <cmath.h>
#include <stdlib.h>

//khai bao prototype
int menu();
void chucNang(int);
int iRandom(int min, int max);
int iRandom(int max);
float fRandom(float min, float max);
float fRandom(float max);
// ham main
int main() {
  while (1) {
    chucNang(menu());
    getch();
    system("cls")
  }
  return 1;
}
