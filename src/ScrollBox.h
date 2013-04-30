#ifndef SCROLLBOX_H
#define SCROLLBOX_H

#include "Interactive.h"

class ScrollBox : public Interactive{
  /* scrollbox will preserve the relative positions of each of these items while scrolling up or down */
  ScrollBox(Drawable ** items, Movable * scrollBar, void * (*myFunc)(void *) = NULL);
  BoundedMovable * scrollBar;
  Drawable ** items;
  Drawable * getImg(){return image;}
  void draw(SDL_Surface * screen);
};

#endif
