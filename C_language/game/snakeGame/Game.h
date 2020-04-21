#ifndef Game_H_
  #include "CommonFunction.h"
  #include "Snake.h"
  #include "Food.h"
  class Game {
    public:
      int score_;
      Game();
      void MenuGame();
      void StartGame();
      void EndGame();
      void GameOver();
      void DrawTopBar();
      void Score(Snake);
  };
#endif
