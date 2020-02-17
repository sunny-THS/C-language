#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <vector>

#define WIDTH_MAIN_OBJECT 80
#define HEIGHT_MAIN_OBJECT 46

class MainObject : public BaseObject {
  public:
    //contructor
    MainObject();
    //destructor
    ~MainObject();

    void HandleInputAction(SDL_Event events);
    void HandleMove();
    void MakeBullet(SDL_Surface* des);

    void SetBulletList(std::vector<BulletObject*> bullet_list) {p_bullet_list_ = bullet_list;}
    std::vector<BulletObject*> GetBulletList() const {return p_bullet_list_;}
  private:
    int x_val_, y_val_;

    // std::vector<Khieu du lieu> tenBien;
    std::vector<BulletObject*> p_bullet_list_; // truong cua MainObject
};

#endif // MAIN_OBJECT_H_
