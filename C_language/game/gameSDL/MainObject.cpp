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
    AmoObject* p_amo = new AmoObject();
    if (events.button.button == SDL_BUTTON_LEFT) {// click chuot phai
      p_amo->SetW_H(WIDTH_LAZE, HEIGHT_LAZE);
      p_amo->LoadIMG("laser.png");
      p_amo->set_type(AmoObject::LAZE);
    }else if (events.button.button == SDL_BUTTON_RIGHT) {// click chuot trai
      p_amo->SetW_H(WIDTH_SPHERE, HEIGHT_SPHERE);
      p_amo->LoadIMG("sphere.png");
      p_amo->set_type(AmoObject::SPHERE);
    }
    // this -> rec_.x giong nhu AmoObject::rec_.x
    p_amo->SetRect(this->rect_.x + WIDTH_MAIN_OBJECT - WIDTH_MAIN_OBJECT*0.3, this->rect_.y + HEIGHT_MAIN_OBJECT - HEIGHT_MAIN_OBJECT*0.4);
    p_amo->set_is_move(true);

    // them vao amo_list
    p_amo_list_.push_back(p_amo);
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
  if (rect_.y < 0 || (rect_.y + HEIGHT_MAIN_OBJECT) > SCREEN_HEIGHT - SCREEN_HEIGHT*0.4) {
    rect_.y -= y_val_;
  }
}
