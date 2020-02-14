#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_

#include "BaseObject.h"

// kich thuoc hinh
#define WIDTH_LAZE 35
#define HEIGHT_LAZE 5

//kich thuoc hinh
#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

class AmoObject : public BaseObject {
  public:
    enum AMO_TYPE {
      NONE = 0,
      LAZE = 1,
      SPHERE = 2
    };
    //contructor
    AmoObject();
    //destructor
    ~AmoObject();

    void HandleInputAction(SDL_Event events);
    void HandleMove(const int& x_border, const int& y_border);

// kieu dan bân ra
    int get_type() const {return amo_type_;}
    void set_type(const int& type) {amo_type_ = type;}

// kiem tra dan ban ra
    bool get_is_move() const {return is_move_;}
    void set_is_move(bool is_move) {is_move_ = is_move;}

    void SetW_H(const int& width, const int& height) {rect_.w = width; rect_.h = height;}
  private:
    int x_val_, y_val_, amo_type_;
    bool is_move_;
};

#endif //AMO_OBJECT_H_
