#include "Drawable.h"
void Drawable::changePosition(int xoffset, int yoffset){
  position.x += xoffset;
  position.y += yoffset;
}
bool Drawable::inRectangle(int x, int y){
  if((x > position.x)
     && (x < position.x + position.w)
     && (y > position.y)
     && (y < position.y + position.h))
    return true;
  return false;
}
void Drawable::setPriority(int x){
  priority = x;
}
bool Drawable::operator<(const Drawable & rhs){
  return priority<rhs.priority;
}
void Drawable::setDimensions(int w, int h){
  position.w = w;
  position.h = h;
}
