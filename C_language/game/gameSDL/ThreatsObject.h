#ifndef THREATS_OBJECT_H_
#define THREATS_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <vector>

#define WIDTH_THREAT 80
#define HEIGHT_THREAT 33

class ThreatsObject : public BaseObject {
  private:
    int x_val_, y_val_;

    std::vector<BulletObject*> p_bullet_list_; // truong cua BulletObject
  public:
    // contructor
    ThreatsObject();
    // destructor
    ~ThreatsObject();

    void HandleMove(const int& x, const int& y);
    void HandleInputAction(SDL_Event events);

    void set_x_val(const int& val) {x_val_ = val;}
    void set_y_val(const int& val) {y_val_ = val;}
    int get_x_val() const {return x_val_;}
    int get_y_val() const {return y_val_;}

    void SetBulletList(std::vector<BulletObject*> bullet_list) {p_bullet_list_ = bullet_list;}
    std::vector<BulletObject*> GetBulletList() const {return p_bullet_list_;}

    // ham khoi tao vien dan (threats)
    void InitBullet();
    void MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit);
};

#endif
