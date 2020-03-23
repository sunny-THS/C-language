#ifndef Snake_H_
  #define Snake_H_
  #include "CommonFunction.h"
  #include "Food.h"
  #include "Game.h"

  class Snake : Food{
    public:
      Snake();
      ~Snake();

      void drawSnake();
      void updateSnake();
      void HandleInputAction();
      int GetSnakeLen() {return snakeLen_-tmp;}
      void HandleCollision();
    protected:
      Game game_;
      int tmp;// tmp variable
      int snakeLen_, speed_;
      TrangThai tt_;
      bool is_move_;
      std::vector<TD> dot_;
      TD oxy_;
  };
#endif
