#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"
#include "AmoObject.h"
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
    void SetAmoList(std::vector<AmoObject*> amo_list) {p_amo_list_ = amo_list;}
    std::vector<AmoObject*> GetAmoList() const {return p_amo_list_;}
  private:
    int x_val_, y_val_;

    // std::vector<Khieu du lieu> tenBien;
    std::vector<AmoObject*> p_amo_list_; // truong cua MainObject
};

#endif // MAIN_OBJECT_H_
