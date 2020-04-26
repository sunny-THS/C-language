#ifndef Game_H_
  #include "CommonFunction.h"
  #include "BaseObject.h"
  #include "Snake.h"
  #include "Food.h"
  #define TEXT_TITLEGAME "\n\t\t\t  _________              __              ________                       \n\t\t\t /   _____/ ____ _____  |  | __ ____    /  _____/_____    _____   ____  \n\t\t\t \\_____  \\ /    \\\\__  \\ |  |/ // __ \\  /   \\  ___\\__  \\  /     \\_/ __ \\ \n\t\t\t /        \\   |  \\/ __ \\|    <\\  ___/  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ \n\t\t\t/_______  /___|  (____  /__|_ \\\\___  >  \\______  (____  /__|_|  /\\___  >\n\t\t\t        \\/     \\/     \\/     \\/    \\/          \\/     \\/      \\/     \\/ "
  #define TITLE "Snake Game"
  #define TEXT_START "Start"
  #define TEXT_NEWGAME "New Game"
  #define TEXT_RESUME "Resume"
  #define TEXT_RESTART "Restart Game"
  #define TEXT_RANK "Rank"
  #define TEXT_HOWTOGAME "How to game"
  #define TEXT_GAMEOVER "Game Over"
  #define TEXT_EXIT "Exit"
  #define HOWTOPLAY \
  "Press w, a, s, d to move snake, press space to pause game and esc to back menu"
  #define HEIGHT_BOARD 3
  #define WIDTH_BOARD 10
  #define WIDTH_PAUSE 30
  #define HEIGHT_PAUSE 10
  struct InformationUser {
    std::string time;
    int score;
  };
  typedef struct InformationUser INFOUSER;
  class Game : public BaseObject{
    private:
      struct tm *localTime_;
      time_t rawTime_;
      int score_;
      INFOUSER ifuser;
    public:
      bool is_run_, is_pause_;
      Game();
      void Setup();
      void MenuGame(int a=Red, int b=Yellow, int c=Yellow, int slt=1);
      int SelectMenu();
      void DrawBoard(int, int, int, int);
      void DelBoard(int, int, int, int);
      void StartGame(Snake, Food, bool mod = false);
      void HowToGame();
      void GameOver();
      void PauseGame();
      void MenuPause(int a = Yellow, int b = White, int c = White);
      void DrawFramePause();
      void DrawTopBar();
      void Score(Snake);
      void SetTime();
  };
#endif
