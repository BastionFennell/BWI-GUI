#ifndef TEXT_INPUT_BOX_H
#define TEXT_INPUT_BOX_H
#include <string>
#include "Interactive.h"

class TextInputBox : public Interactive{
 public:
  TextInputBox(Drawable * inputBox, TTF_Font * myFont, SDL_Color myColor,  void * (*myFunc)(void *) = NULL);
  ~TextInputBox(){delete text;}
  std::string getText();
  Text * getTextObject(){return text;}
  void draw(SDL_Surface * display);
  Drawable * getImg();
  void * changeState(int x, int y, int click, void * package = NULL); //pass in string as package?
  Text * text;
  Drawable * box;
  //clickDown, clickUp, holdState
};
#endif
