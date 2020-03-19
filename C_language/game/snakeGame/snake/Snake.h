#ifndef Snake_H_
  #define Snake_H_
  #include "CommonFunction.h"

  class Snake{
    private:
      int snakeLen_, speed_;
      TrangThai tt_;
      bool is_move_;
    public:
      Snake();
      ~Snake();

      void drawSnake();
      void update();
      void control();
    protected:
      std::vector<TD> dot_;
      TD oxy_;
  };
#endif
