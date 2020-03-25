#ifndef Info_User_H
  #define Info_User_H
  #include "CommonFunction.h"
  #include <string.h>

  #define TEXT_TITLE "\n\n\t\t ######  ##    ##    ###    ##    ## ########     ######      ###    ##     ## ########\n\t\t##    ## ###   ##   ## ##   ##   ##  ##          ##    ##    ## ##   ###   ### ##      \n\t\t##       ####  ##  ##   ##  ##  ##   ##          ##         ##   ##  #### #### ##      \n\t\t ######  ## ## ## ##     ## #####    ######      ##   #### ##     ## ## ### ## ######  \n\t\t      ## ##  #### ######### ##  ##   ##          ##    ##  ######### ##     ## ##      \n\t\t##    ## ##   ### ##     ## ##   ##  ##          ##    ##  ##     ## ##     ## ##      \n\t\t ######  ##    ## ##     ## ##    ## ########     ######   ##     ## ##     ## ########"
  #define TITLE "Snake Game"
  #define TEXT_START "Start Game"
  #define TEXT_HOWTOGAME "How to game"
  #define TEXT_EXIT "Exit"

  class InfoUser {
    private:
      int score_;
      char user_name_[50];
      time_t rawTime;
      struct tm *localTime;
    public:
      InfoUser();
      int titleGame();
      void inputUserName();
      void menu(char *start, char *help, char *e, int, int, int);
      void boardInfoUser();
      void SetScore(const int& s) {score_ = s;}
      void SetTime();
      void SetName(const char*s) {strcpy(user_name_, s);}
      char* GetName() {return user_name_;}
  };
#endif
