#ifndef PICTURE_H
#define PICTURE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>
#include "Drawable.h"

class Picture : public Drawable{
 public:
  Picture(std::string fileName, int x, int y);
  void draw(SDL_Surface * display);
  SDL_Surface * image;
};
#endif
