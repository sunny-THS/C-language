#ifndef Snake_H
  #define Snake_H
  #include "CommonFunction.h"
  #include "BaseObject.h"
  #include "Food.h"
  class Snake : public BaseObject {
    public:
      Snake();
      ~Snake();
      void Setup();
      void Draw();
      void Update();
      void DelCase(int, int shape = 32);
      int HandleInputAction();
      void HandleCollision(Food&);
      std::vector<Rect> dot_;
      int len_start_;
      TrangThai tt_;
      bool is_move_;
  };
#endif
