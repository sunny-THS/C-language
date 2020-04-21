#ifndef Snake_H
  #define Snake_H
  #include "CommonFunction.h"
  #include "Food.h"
  class Snake : public Food {
    public:
      Snake();
      ~Snake();
      void Setup();
      void Draw();
      void Update();
      void SetRect(const int x, const int y) {rect_.x=x; rect_.y=y;}
      Rect GetRect() {return rect_;}
      void HandleInputAction();
      int Collision();
    protected:
      Rect rect_;
      std::vector<Rect> dot_;
      TrangThai tt_;
      bool is_move_, is_pause_;
      int len_start_;
  };
#endif
