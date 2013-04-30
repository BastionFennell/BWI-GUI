#ifndef ANIMATED_H
#define ANIMATED_H
#include "Drawable.h"
#include "Picture.h"
class Animated : public Drawable{
 public:
  Animated(Drawable * images[], int numFrames, unsigned int frameDelay, int x, int y);
  void draw(SDL_Surface * display);
  Drawable ** images;
  unsigned int frameDelay;
  int numFrames;
  int currentFrame;
};
#endif
