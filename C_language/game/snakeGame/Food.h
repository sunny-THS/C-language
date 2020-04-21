#ifndef Food_H_
  #define Food_H_
  #include "CommonFunction.h"
  class Food {
     public:
       Food();
       ~Food();
       void Setup();
       void DrawFood();
       int GetIX() {return CommonFunction::random(WIDTH-2);} // return x index
       int GetIY() {return CommonFunction::random(HEIGHT-1, 3);} // return y index
       void UpdateFruit(int x, int y, int i);
     protected:
       Rect fruit_[AMOUNT_FOOD];
  };
#endif
