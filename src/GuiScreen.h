#ifndef GUI_SCREEN_H
#define GUI_SCREEN_H
#include "Screen.h"
class GuiScreen : public Screen{
 public:
  Screen * draw(SDL_Surface * display);
};
#endif
