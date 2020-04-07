#ifndef Paddle_H_
  #define Paddle_H_
  #include "CommonFunction.h"
  #include "BaseObject.h"
  class Paddle : BaseObject{
    public:
      int w_, h_, shape_;
      Paddle(bool left=true);
      void Draw();
      void move(float);
  };
#endif
