#ifndef Game_H_
  #define Game_H_

  #include "CommonFunction.h"
  #include "Snake.h"
  class Game : Snake {
    public:
      int score;
      
      Game();
      ~Game();
      int GetScore() {return score;}
  };
#endif
