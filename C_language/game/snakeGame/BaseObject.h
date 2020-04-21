#ifndef Base_Object_H_
  #define Base_Object_H_
  #include "CommonFunction.h"
  class BaseObject {
    public:
      BaseObject();
      ~BaseObject();
      void SetRect(const int x, const int y) {rect_.x=x; rect_.y=y;}
      Rect GetRect() {return rect_;}
    protected:
       Rect rect_;
  };
#endif
