#ifndef MOVABLE_H
#define MOVABLE_H
#include "Interactive.h"

/*
 * A class for images that move when interacted with by the user
 */
class Movable : public Interactive{
 public:
  Drawable * image;
  Movable(Drawable * img);
  void * changeState(int x, int y, int click, void * package = NULL);
  Drawable * getImg(){return image;}
  void draw(SDL_Surface * display);
  int x, y;
};
#endif
