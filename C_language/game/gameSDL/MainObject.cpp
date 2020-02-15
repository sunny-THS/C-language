#include "MainObject.h"

MainObject::MainObject() {
  rect_.x = 0;
  rect_.y = 0;
  rect_.w = WIDTH_MAIN_OBJECT;
  rect_.h = HEIGHT_MAIN_OBJECT;
  x_val_ = 0;
  y_val_ = 0;
}
MainObject::~MainObject() {}

void MainObject::HandleInputAction(SDL_Event events) {
  if (events.type == SDL_KEYDOWN) { // nhan phim
    switch (events.key.keysym.sym) {
      case SDLK_UP:
      case SDLK_w:
        y_val_ -= HEIGHT_MAIN_OBJECT/6;
        break;
      case SDLK_DOWN:
      case SDLK_s:
        y_val_ += HEIGHT_MAIN_OBJECT/6;
        break;
      case SDLK_LEFT:
      case SDLK_a:
        x_val_ -= WIDTH_MAIN_OBJECT/6;
        break;
      case SDLK_RIGHT:
      case SDLK_d:
        x_val_ += WIDTH_MAIN_OBJECT/6;
        break;
    }
  }else if (events.type == SDL_KEYUP) { // buong phim
    switch (events.key.keysym.sym) {
      case SDLK_UP:
      case SDLK_w:
        y_val_ += HEIGHT_MAIN_OBJECT/6;
        break;
      case SDLK_DOWN:
      case SDLK_s:
        y_val_ -= HEIGHT_MAIN_OBJECT/6;
        break;
      case SDLK_LEFT:
      case SDLK_a:
        x_val_ += WIDTH_MAIN_OBJECT/6;
        break;
      case SDLK_RIGHT:
      case SDLK_d:
        x_val_ -= WIDTH_MAIN_OBJECT/6;
        break;
    }
  }else if (events.type == SDL_MOUSEBUTTONDOWN) { // xu ly chuot
    BulletObject* p_bullet = new BulletObject();
    if (events.button.button == SDL_BUTTON_LEFT) {// click chuot phai
      p_bullet->SetW_H(WIDTH_LAZE, HEIGHT_LAZE);
      p_bullet->LoadIMG("laser.png");
      p_bullet->set_type(BulletObject::LAZE);
    }else if (events.button.button == SDL_BUTTON_RIGHT) {// click chuot trai
      p_bullet->SetW_H(WIDTH_SPHERE, HEIGHT_SPHERE);
      p_bullet->LoadIMG("sphere.png");
      p_bullet->set_type(BulletObject::SPHERE);
    }
    // this -> rec_.x giong nhu BulletObject::rec_.x
    p_bullet->SetRect(this->rect_.x + WIDTH_MAIN_OBJECT - WIDTH_MAIN_OBJECT*0.3, this->rect_.y + HEIGHT_MAIN_OBJECT - HEIGHT_MAIN_OBJECT*0.15);
    p_bullet->set_is_move(true);

    // them vao bullet_list
    p_bullet_list_.push_back(p_bullet);
  }else if (events.type == SDL_MOUSEBUTTONUP) {
    /* code */
  }
}
void MainObject::HandleMove() {
  rect_.x += x_val_;
  if (rect_.x < 0 || (rect_.x + WIDTH_MAIN_OBJECT) > SCREEN_WIDTH) {
    rect_.x -= x_val_;
  }
  rect_.y += y_val_;
  if (rect_.y < 0 || (rect_.y + HEIGHT_MAIN_OBJECT) > SCREEN_HEIGHT*0.8) {
    rect_.y -= y_val_;
  }
}
