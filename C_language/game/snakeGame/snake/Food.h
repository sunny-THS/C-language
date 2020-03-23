#ifndef Food_H_
  #define Food_H_
  #include "CommonFunction.h"
  class Food {
     public:
       Food();
       ~Food();
       void drawFood();
       void updateFruit();
     protected:
       TD fruit_[AMOUNT_FOOD];
  };
#endif
