#ifndef Food_H_
  #define Food_H_
  #include "CommonFunction.h"
  #include "BaseObject.h"
  class Food : public BaseObject{
     public:
       Rect fruit_[AMOUNT_FOOD];
       Food();
       ~Food();
       void Setup();
       void DrawFood();
       void DrawOneFood(int);
       int GetIX() {return CommonFunction::random(WIDTH-2);} // return x index
       int GetIY() {return CommonFunction::random(HEIGHT-1, 3);} // return y index
       void UpdateFruit(int x, int y, int i);
  };
#endif
