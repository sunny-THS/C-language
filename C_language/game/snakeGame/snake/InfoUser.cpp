#include "InfoUser.h"

InfoUser::InfoUser() {
  score_ = 0;
  strcpy(user_name_, "");
  is_getInfomation = true;
}
void InfoUser::SetTime() {
  time(&rawTime_);
  localTime_ = localtime(&rawTime_);
  localTime_->tm_year+=1900;
  localTime_->tm_mon++;
}
int InfoUser::titleGame() {
  int y = Green, n = White;//y is select, n is no select
  int select = 1;//1 is start game, 2 is howToPlay, 3 is exit

  CommonFunction::textColor(Green);
  puts(TEXT_TITLE);
  while (1) {
    switch (select) {
      case 1: menu(TEXT_START, TEXT_HOWTOGAME, TEXT_EXIT, TEXT_RANK, y, n, n, n); break;
      case 2: menu(TEXT_START, TEXT_HOWTOGAME, TEXT_EXIT, TEXT_RANK, n, y, n, n); break;
      case 3: menu(TEXT_START, TEXT_HOWTOGAME, TEXT_EXIT, TEXT_RANK, n, n, y, n); break;
      case 4: menu(TEXT_START, TEXT_HOWTOGAME, TEXT_EXIT, TEXT_RANK, n, n, n, y); break;
    }

    if (kbhit()) { // press keysboard
      char key = _getch();
      if (key == 'w' || key == 'W' || key == 56 || key == 72) {
        select--;
        if (select<1) {
          select = 4;
        }
      }else if (key == 's' || key == 'S' || key == 50 || key == 80) {
        select++;
        if (select>4) {
          select = 1;
        }
      }else if (key == 13) {
        return select;
      }
    }
  }
}
// creat menu game
void InfoUser::menu(char *start, char *help, char *e, char* rank, int a, int b, int c, int d){
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(start))/2, CONSOLE_HEIGHT/2-3);
  CommonFunction::textColor(a);
  puts(start);
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(help))/2, CONSOLE_HEIGHT/2+2-3);
  CommonFunction::textColor(b);
  puts(help);
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(rank))/2, CONSOLE_HEIGHT/2+4-3);
  CommonFunction::textColor(c);
  puts(rank);
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(e))/2, CONSOLE_HEIGHT/2+6-3);
  CommonFunction::textColor(d);
  puts(e);
}
void InfoUser::boardInfoUser() {
  CommonFunction::textColor(Green);
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(TITLE))/2, HEIGHT_BOARD_INFO/3);
  puts(TITLE);
  CommonFunction::textColor(White);
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(user_name_)-4)/2, HEIGHT_BOARD_INFO/2);
  std::cout << "Hi, " << GetName();
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-8)/2, HEIGHT_BOARD_INFO-HEIGHT_BOARD_INFO/4);
  std::cout << "Score: " << score_;
}
// user name player
void InfoUser::inputUserName() {
  CommonFunction::cls();
  char name[50];
  char label[] = "User name: ";
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(label))/2, CONSOLE_HEIGHT/2);
  std::cout << label;
  SetName(gets(name));
}
// save infomation player
void InfoUser::saveInfo() {
  SetTime();
  std::ofstream log;
  log.open("../Debug/logGame.txt", std::ios::app);
  log << localTime_->tm_mday<<'/'<<localTime_->tm_mon<<'/'<<localTime_->tm_year;
  log << ' '<<localTime_->tm_hour<<':'<<localTime_->tm_min<<':'<<localTime_->tm_sec<<"\n";
  log << user_name_ << "\n";
  log << score_ << "\n";

  log.close();
}
void InfoUser::SetInfo() {
  std::ifstream Infomation("../Debug/logGame.txt");
  while(is_getInfomation) {
    if (!getline(Infomation, inf_.time)) {
      is_getInfomation = false;
      break;
    }
    if (!getline(Infomation, inf_.name)) {
      is_getInfomation = false;
      break;
    }
    if (!getline(Infomation, inf_.score)) {
      is_getInfomation = false;
      break;
    }
    rank_.push_back(inf_);
  }

  Infomation.close();
}
void InfoUser::printf_Rank() {
  SetInfo();
  CommonFunction::cls();
  // sorting rank
  int sortingJ;
  std::string tmpTime;
  std::string tmpName;
  std::string tmpScore;
  for (int sortingI = 1; sortingI < rank_.size(); sortingI++) {
    tmpTime = rank_[sortingI].time;
    tmpName = rank_[sortingI].name;
    tmpScore = rank_[sortingI].score;
    sortingJ = sortingI - 1;
    // stoi function to change string -> int
    while (sortingJ>=0 && stoi(tmpScore)> stoi(rank_[sortingJ].score)) {
      rank_[sortingJ+1] = rank_[sortingJ];
      sortingJ--;
    }
    rank_[sortingJ+1].time = tmpTime;
    rank_[sortingJ+1].name = tmpName;
    rank_[sortingJ+1].score = tmpScore;
    tmpTime.clear();
    tmpName.clear();
    tmpScore.clear();
  }
  //_____________
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(TEXT_RANK))/2,CENTER_CONSOLE_HEIGHT-LIMIT_RANK/2-2);
  CommonFunction::textColor(Red);
  puts(TEXT_RANK);
  while (1) {
    CommonFunction::textColor(CadetBlue);
    CommonFunction::gotoxy((CONSOLE_WIDTH-4)/2-LIMIT_SPACE_TEXT,CENTER_CONSOLE_HEIGHT-LIMIT_RANK/2-1);
    std::cout << "Name";
    CommonFunction::gotoxy((CONSOLE_WIDTH-5)/2+LIMIT_SPACE_TEXT,CENTER_CONSOLE_HEIGHT-LIMIT_RANK/2-1);
    std::cout << "Score";
    CommonFunction::textColor(White);
    for (int i = 0; i < LIMIT_RANK; i++) {
      CommonFunction::gotoxy((CONSOLE_WIDTH)/2-LIMIT_SPACE_TEXT-2,CENTER_CONSOLE_HEIGHT-LIMIT_RANK/2+i);
      std::cout << rank_[i].name;
      CommonFunction::gotoxy((CONSOLE_WIDTH)/2+LIMIT_SPACE_TEXT-3,CENTER_CONSOLE_HEIGHT-LIMIT_RANK/2+i);
      std::cout << rank_[i].score;
    }
    if (kbhit()) {
      char key = _getch();
      if (key == 27) {
        break;
      }
    }
  }
}
void InfoUser::printf_Howtogame() {
  CommonFunction::cls();
  while (1) {
    CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(HOWTOPLAY))/2, CONSOLE_HEIGHT/2);
    CommonFunction::textColor(Green);
    puts(HOWTOPLAY);
    if (kbhit()) {
      char key = _getch();
      if (key == 27) {
        break;
      }
    }
  }
}
