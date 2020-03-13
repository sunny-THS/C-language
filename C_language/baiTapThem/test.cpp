#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
void swap(char& a, char& b) {
  char t = a;
  a = b;
  b = t;
}
int main() {
  vector<char> text;
  char t[10];
  gets(t);
  for(int i=0; i< strlen(t); i++) {
    text.push_back(t[i]);
  }
  swap(text[1], text[2]);
  for (int i = 0; i < text.size(); i++) {
    cout << text.at(i);
  }
  system("pause>nul");
  return 0;
}
