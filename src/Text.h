#ifndef TEXT_H
#define TEXT_H
#include <vector>
#include <SDL/SDL_ttf.h>
#include "Drawable.h"

#define SOLID   0
#define SHADED  1
#define BLENDED 2
class Text : public Drawable{
 public:
  Text(TTF_Font * myFont, std::string message, int x = 0, int y = 0, SDL_Color * color = NULL);
  void setText(std::string text);
  std::string myText;
  std::string getText();
  void draw(SDL_Surface * display);
  SDL_Color color;
  TTF_Font * font;
  int lineSkip;
  std::vector<SDL_Surface *> image;
};

#endif
