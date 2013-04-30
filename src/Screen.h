#ifndef SCREEN_H
#define SCREEN_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Drawable.h"
#include "Interactive.h"
#include "Text.h"
class Interactive;

class Screen {
 public:
  Screen();
  Screen * addItem(Drawable * item);
  Screen * addItem(Interactive * item);
  //add the end of the draw loop, the next screen's pointer will be output
  virtual Screen * draw(SDL_Surface * display) = 0;
  std::vector<Drawable*> drawableItems;
  std::vector<Interactive*> interactiveItems;
  std::vector<Interactive*> inputItems;
};
#endif
