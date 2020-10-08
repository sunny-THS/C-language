#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
  int xPos, yPos;
  int lParam;
  while (WM_MOUSEMOVE) {
    xPos = GET_X_LPARAM(lParam);
    yPos = GET_Y_LPARAM(lParam);
  }
  return 0;
}
