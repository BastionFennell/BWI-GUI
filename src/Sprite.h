#ifndef SPRITE_H
#define SPRITE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>
#include "Drawable.h"

/*
 * A class for images that move when interacted with by the user
 */

class Sprite : public Drawable{
 public:
  Sprite(std::string fileName, int xpos, int ypos);
  ~Sprite();
  bool loadImages(std::string fileName);
  void changePosition(int x, int y, int state);
  void draw(SDL_Surface * screen);
  int x, y;
  int click;
  SDL_Rect * boundaries; //currently not used at all, will eventually define a boundary for the sprite to move around in
  //note to self: add second SDL_Surface to the array to represent the original position of the sprite for resetting purposes
  SDL_Rect** edge;
  SDL_Surface** img;
  static const int clickDown;
  static const int clickUp;
  static const int hold;
};
#endif
