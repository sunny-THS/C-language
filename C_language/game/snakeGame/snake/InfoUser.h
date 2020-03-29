#ifndef Info_User_H
  #define Info_User_H
  #include "CommonFunction.h"
  #include <cstring>
  #include <fstream>
  #include <string>

  #define TEXT_TITLE "\n\n\t\t ######  ##    ##    ###    ##    ## ########     ######      ###    ##     ## ########\n\t\t##    ## ###   ##   ## ##   ##   ##  ##          ##    ##    ## ##   ###   ### ##      \n\t\t##       ####  ##  ##   ##  ##  ##   ##          ##         ##   ##  #### #### ##      \n\t\t ######  ## ## ## ##     ## #####    ######      ##   #### ##     ## ## ### ## ######  \n\t\t      ## ##  #### ######### ##  ##   ##          ##    ##  ######### ##     ## ##      \n\t\t##    ## ##   ### ##     ## ##   ##  ##          ##    ##  ##     ## ##     ## ##      \n\t\t ######  ##    ## ##     ## ##    ## ########     ######   ##     ## ##     ## ########"
  #define TITLE "Snake Game"
  #define TEXT_START "Start Game"
  #define TEXT_NEWGAME "New Game"
  #define TEXT_RESUME "Resume"
  #define TEXT_RESTART "Restart Game"
  #define TEXT_RANK "Rank"
  #define TEXT_HOWTOGAME "How to game"
  #define TEXT_GAMEOVER "Game Over"
  #define TEXT_EXIT "Exit"
  #define LIMIT_RANK 5
  #define LIMIT_SPACE_TEXT 15

  struct infomation {
    std::string time, name, score;
  };
  class InfoUser {
    private:
      int score_;
      bool is_getInfomation;
      char user_name_[50];
      time_t rawTime_;
      struct tm *localTime_;
      infomation inf_;
      std::vector<infomation> rank_;
    public:
      InfoUser();
      int titleGame();
      void saveInfo();
      void SetInfo();
      void printf_Rank();
      void inputUserName();
      void menu(char *start, char *help, char *e, char* rank, int, int, int, int);
      void boardInfoUser();
      void SetScore(const int& s) {score_ = s;}
      void SetTime();
      void SetName(const char*s) {strcpy(user_name_, s);}
      char* GetName() {return user_name_;}
  };
#endif
