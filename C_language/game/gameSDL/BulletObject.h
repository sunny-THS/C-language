#ifndef BULLET_OBJECT_H_
#define BULLET_OBJECT_H_

#include "BaseObject.h"

// kich thuoc hinh
#define WIDTH_LAZE 35
#define HEIGHT_LAZE 5

//kich thuoc hinh
#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

class BulletObject : public BaseObject {
  public:
    enum BULLET_TYPE {
      NONE = 0,
      LAZE = 1,
      SPHERE = 2
    };
    //contructor
      BulletObject();
    //destructor
    ~ BulletObject();

    void HandleInputAction(SDL_Event events);
    void HandleMove(const int& x_border, const int& y_border);
    void HandleMoveRightToLeft();

// kieu dan bân ra
    int get_type() const {return bullet_type_;}
    void set_type(const int& type) {bullet_type_ = type;}

// kiem tra dan ban ra
    bool get_is_move() const {return is_move_;}
    void set_is_move(bool is_move) {is_move_ = is_move;}

    void SetW_H(const int& width, const int& height) {rect_.w = width; rect_.h = height;}

    void set_x_val(const int& x_val) {x_val_ = x_val;}
    int get_x_val() const {return x_val_;}
    void set_y_val(const int& y_val) {y_val_ = y_val;}
    int get_y_val() const {return y_val_;}

  private:
    int x_val_, y_val_, bullet_type_;
    bool is_move_;
};

#endif //BULLET_OBJECT_H_
