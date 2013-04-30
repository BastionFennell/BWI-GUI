#ifndef BOUNDED_MOVABLE_H
#define BOUNDED_MOVABLE_H
#include "Interactive.h"
#include "Movable.h"
class BoundedMovable : public Interactive{
 public:
  BoundedMovable(Movable * item, int x, int y, int w, int h);
  SDL_Rect bounds;
  void * changeState(int x, int y, int click, void * package = NULL);
  void draw(SDL_Surface * display);
  Drawable * getImg();
  bool wbound;
  bool hbound;
  Movable * item;
};
#endif
