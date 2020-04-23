#ifndef Game_H_
  #include "CommonFunction.h"
  #include "BaseObject.h"
  #include "Snake.h"
  #include "Food.h"
  #define TEXT_TITLEGAME "\n\t\t\t  _________              __              ________                       \n\t\t\t /   _____/ ____ _____  |  | __ ____    /  _____/_____    _____   ____  \n\t\t\t \\_____  \\ /    \\\\__  \\ |  |/ // __ \\  /   \\  ___\\__  \\  /     \\_/ __ \\ \n\t\t\t /        \\   |  \\/ __ \\|    <\\  ___/  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ \n\t\t\t/_______  /___|  (____  /__|_ \\\\___  >  \\______  (____  /__|_|  /\\___  >\n\t\t\t        \\/     \\/     \\/     \\/    \\/          \\/     \\/      \\/     \\/ "
  #define TITLE "Snake Game"
  #define TEXT_START "Start"
  #define TEXT_GAMEMODE "Game Mode"
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

  class Game : public BaseObject{
    public:
      int score_;
      bool is_work;
      Game();
      void MenuGame(int a=CadetBlue, int b=White, int c=White, int d=White, int slt=1);
      int SelectMenu();
      void DrawBoard(int, int, int index = 0);
      void DelBoard(int, int, int index = 0);
      void StartGame(Snake, Food);
      void EndGame();
      void GameOver();
      void DrawTopBar();
      void Score(Snake);
  };
#endif
