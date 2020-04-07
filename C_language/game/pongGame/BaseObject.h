#ifndef Base_Object_H_
  #define Base_Object_H_
  #include "CommonFunction.h"
  struct Rect {
    float x, y;
  };
  class BaseObject {
    public:
      BaseObject();
      void Set_Rect(float, float);
      float Get_X() {return rect_.x;}
      float Get_Y() {return rect_.y;}
    protected:
      Rect rect_;
  };
#endif
