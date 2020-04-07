#include "BaseObject.h"
BaseObject::BaseObject() {
  rect_.x=0;
  rect_.y=0;
}
void BaseObject::Set_Rect(float x, float y) {
  rect_.x = x;
  rect_.y = y;
}
