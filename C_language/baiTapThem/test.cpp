#include <iostream>
#include <Windows.h>
using namespace std;
void GotoXY(short int x, short int y) {
  HANDLE hConsoleOutput;
  COORD Cursor_an_Pos = {x, y};
  hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
int main() {
  int n = 3;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      GotoXY(j, i);
      if (i==j || i+j==n-1) {
        putchar(42);
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 5; j < n+5; j++) {
      GotoXY(j, i);
      if ((i==0|| i==n-1)||(!(i==0|| i==n-1)&&(j==5||j==n+5-1))) {
        putchar(42);
      }
    }
  }
  system("pause>nul");
  return 0;
}
