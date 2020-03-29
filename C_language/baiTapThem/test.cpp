#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
struct infomation {
  string time;
  string name;
  string score;
};
int main() {
  infomation info;
  vector<infomation> t;
  bool is_getInfomation = false;
  // ifstream Infomation("D:/visual/SnakeGame/Debug/logGame.txt");
  // getline(Infomation, info.time);
  // getline(Infomation, info.name);
  // char * cstr = new char[info.name.length()+1];
  // strcpy(cstr, info.name.c_str());
  // char *p = strtok(cstr, " "); // tach chuoi
  // while (p != NULL) {
  //   cout << p << endl;
  //   p = strtok(NULL, " ");
  // }
  // delete[] cstr;
  ifstream Infomation("D:/visual/SnakeGame/Debug/logGame.txt");
  string s;
  getline(Infomation, s);
  cout << s;
  if (s.compare("")==0) {
    cout << 1;
  }
  while(is_getInfomation) {
    if (!getline(Infomation, info.time)) {
      is_getInfomation = false;
      break;
    }
    if (!getline(Infomation, info.name)) {
      is_getInfomation = false;
      break;
    }
    if (!getline(Infomation, info.score)) {
      is_getInfomation = false;
      break;
    }
    t.push_back(info);
  }
  for(auto item=0; item < t.size(); item++) {
    cout << t[item].score<<endl;
  }
  return 0;
}
