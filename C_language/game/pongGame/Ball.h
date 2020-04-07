#ifndef Ball_H_
  #define Ball_H_
  #include "CommonFunction.h"
  #include "BaseObject.h"
  class Ball : BaseObject{
    private:
      float speed_x_, speed_y_;
    public:
      Ball();
      Ball(float, float);
      void Draw();
      void Update();
      void edgesCollision();
      void reset();
      void Set_speedX(float speed) {speed_x_=speed;}
  };
#endif
