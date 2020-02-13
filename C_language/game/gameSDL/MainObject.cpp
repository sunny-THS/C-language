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
        break;
      case SDLK_DOWN:
        break;
      case SDLK_LEFT:
        break;
      case SDLK_RIGHT:
        break;
    }
  }else if (events.type == SDL_KEYUP) { // buong phim

  }else if (events.type == SDL_MOUSEBUTTONDOWN) { // xu ly chuot

  }else {

  }
}
void MainObject::HandleMove() {}
