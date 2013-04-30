#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Global_Defines.h"

class Drawable{
 public:
 Drawable():priority(5){}
 Drawable(int x, int y):priority(1){position.x = x; position.y = y;}
  virtual void draw(SDL_Surface * display) = 0;
  bool operator<(const Drawable & rhs);
  void setPriority(int x);
  bool inRectangle(int x, int y);
  void changePosition(int x, int y);
  void setDimensions(int w, int h);
  // protected:
  SDL_Rect position;
  int priority;
};
#endif
