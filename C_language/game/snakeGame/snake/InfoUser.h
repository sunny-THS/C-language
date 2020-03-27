#ifndef Info_User_H
  #define Info_User_H
  #include "CommonFunction.h"
  #include <string.h>
  #include <fstream>

  #define TEXT_TITLE "\n\n\t\t ######  ##    ##    ###    ##    ## ########     ######      ###    ##     ## ########\n\t\t##    ## ###   ##   ## ##   ##   ##  ##          ##    ##    ## ##   ###   ### ##      \n\t\t##       ####  ##  ##   ##  ##  ##   ##          ##         ##   ##  #### #### ##      \n\t\t ######  ## ## ## ##     ## #####    ######      ##   #### ##     ## ## ### ## ######  \n\t\t      ## ##  #### ######### ##  ##   ##          ##    ##  ######### ##     ## ##      \n\t\t##    ## ##   ### ##     ## ##   ##  ##          ##    ##  ##     ## ##     ## ##      \n\t\t ######  ##    ## ##     ## ##    ## ########     ######   ##     ## ##     ## ########"
  #define TITLE "Snake Game"
  #define TEXT_START "Start Game"
  #define TEXT_NEWGAME "New Game"
  #define TEXT_RESUME "Resume"
  #define TEXT_RESTART "Restart Game"
  #define TEXT_HOWTOGAME "How to game"
  #define TEXT_GAMEOVER "Game Over"
  #define TEXT_EXIT "Exit"

  struct infomation {
    char name[50];
    int score;
  };

  class InfoUser {
    private:
      int score_;
      char user_name_[50];
      time_t rawTime_;
      struct tm *localTime_;
      infomation inf;
      std::vector<infomation> rank_;
    public:
      InfoUser();
      int titleGame();
      void saveInfo();
      void inputUserName();
      void menu(char *start, char *help, char *e, int, int, int);
      void boardInfoUser();
      void SetScore(const int& s) {score_ = s;}
      void SetTime();
      void SetName(const char*s) {strcpy(user_name_, s);}
      char* GetName() {return user_name_;}
  };
#endif
