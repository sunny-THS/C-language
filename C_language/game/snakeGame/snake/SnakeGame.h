#ifndef Snake_H_
  #define Snake_H_
  #include "CommonFunction.h"
  #include "InfoUser.h"
  #include "Food.h"

  class SnakeGame : Food {
    private:
      InfoUser info;
    public:
      SnakeGame();
      ~SnakeGame();

      void Init();
      void draw();
      void drawBoardGame();
      void drawBoardInfo();
      void drawBodySnake();
      void updateSnake();
      void HandleInputAction();
      void HandleCollision();
      void HandleScore(int index);
      int boardSelect();
      void titleSelect(const int& a, const int& b, const int& c, const int& d = White);
      void GameOver();
    protected:
      int snakeLen_, speed_;
      TrangThai tt_;
      bool is_move_, is_pause_;
      std::vector<TD> dot_;
      TD oxy_;
  };
#endif
