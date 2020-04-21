#ifndef Game_H_
  #include "CommonFunction.h"
  #include "Snake.h"
  #include "Food.h"
  class Game{
    public:
      Snake snake_;
      Food food_;
      int score_;
      void DrawTopBar();
      void HandleCollision();
  };
#endif
