#ifndef INTERACTIVE_H
#define INTERACTIVE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include "Drawable.h"
#include "Screen.h"

class Screen;

class Interactive{
 public:
  Interactive(void * (*myFunc)(void *) = NULL);
  virtual void draw(SDL_Surface * display) = 0;
  /* Returns pointer upon unusual event */
  virtual void * changeState(int x, int y, int click, void * package = NULL) = 0;
  virtual Drawable * getImg() = 0;
  void * (*myFunction)(void *);
  void setPriority(int x);
  bool operator<(const Interactive & rhs);
  static const int clickDown;
  static const int clickUp;
  static const int holdState;
  int currentState;
  int priority;
};
#endif
