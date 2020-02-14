#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunction.h"

// lop co so
class BaseObject {
  public:
    // contructor
    BaseObject();
    // destructor
    ~BaseObject();
    void Show(SDL_Surface* des);
    bool LoadIMG(const char* file_name);

    void SetRect(const int& x, const int& y){rect_.x = x, rect_.y = y;}
    SDL_Rect GetRect() const{return rect_;}
    SDL_Surface* GetSurface(){return p_object_;}
  protected:
    SDL_Rect rect_;
    SDL_Surface* p_object_; //bien thanh vien
};

#endif //BASE_OBJECT_H_
