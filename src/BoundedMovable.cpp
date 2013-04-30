#include "BoundedMovable.h"

BoundedMovable::BoundedMovable(Movable * item, int x, int y, int w, int h){
  h > 0 ? hbound = true : hbound = false;
  w > 0 ? wbound = true : wbound = false;
  if(hbound)
    bounds.h = h;
  if(wbound)
    bounds.w = w;
  bounds.x = x;
  bounds.y = y;
  this->item = item;
}
void BoundedMovable::draw(SDL_Surface * display){
  item->draw(display);
}
Drawable * BoundedMovable::getImg(){
  return item->getImg();
}
void * BoundedMovable::changeState(int x, int y, int click, void * package){
  //cap x and y, naive (wrong) implementation
  if(wbound){
    if(x < bounds.x)
      x = bounds.x;
    if(x > bounds.x + bounds.w)
      x = bounds.x + bounds.w;
  }
  if(hbound){
    if(y < bounds.y)
      y = bounds.y;
    if(y > bounds.y + bounds.h)
      y = bounds.y + bounds.h;
  }
  item->changeState(x, y, click, package);
  return NULL;
}
