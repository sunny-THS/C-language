#ifndef Food_H_
  #define Food_H_
  #include "CommonFunction.h"
  class Food {
     public:
       Food();
       ~Food();
       void setup();
       void drawFood();
       int GetIX() {return CommonFunction::random(LIMIT_BOARD_GAME-1);} // return x index
       int GetIY() {return CommonFunction::random(CONSOLE_HEIGHT-1);} // return y index
       void updateFruit(int x, int y, int i);
     protected:
       TD fruit_[AMOUNT_FOOD];
  };
#endif
