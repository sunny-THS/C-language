#ifndef Ball_H_
  #define Ball_H_
  #include "CommonFunction.h"
  class Ball {
    private:
      float speed_x_, speed_y_;
    public:
      float x_, y_;
      Ball();
      Ball(float, float);
      void Draw();
      void Update();
      void edgesCollision();
      void reset();
  };
#endif
