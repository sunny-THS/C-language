#include<iostream>
#include<cstring>
using namespace std;
void getTime(char* time) {
  int tmp1, tmp2, h, i, len=strlen(time);
  i = 0;
  while (time[i]!=':') {
    i++;
  }
  if (i-1) {
    tmp1 = time[0] - '0';
    tmp2 = time[1] - '0';
    h = tmp1*10+tmp2;
  }else {
    h = time[0] - '0';
  }
  if (time[len-2]=='A' || time[len-2]=='a') {
    if (h==12) {
      cout << "00";
      for (int nn = i; nn < len-2; nn++) {
        cout << time[nn];
      }
    }else {
      if (h<10) {
        cout << 0;
      }
      for (int nn = 0; nn < len-2; nn++) {
        cout << time[nn];
      }
    }
  }else {
    if (h==12) {
      cout << h;
      for (int nn = i; nn < len-2; nn++) {
        cout << time[nn];
      }
    }else {
      h+=12;
      cout << h;
      for (int nn = i; nn < len-2; nn++) {
        cout << time[nn];
      }
    }
  }
}
int main() {
  char a[20];
  // gets(a);
  fgets(a, 9, stdin); // stdin : standard input
  getTime(a);
  return 0;
}
