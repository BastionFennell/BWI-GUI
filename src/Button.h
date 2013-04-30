#ifndef BUTTON_H
#define BUTTON_H
#include "Screen.h"
#include "Drawable.h"
#include "Global_Defines.h"
#include "Interactive.h"

#define NUM_STATES 3 //there is a #define here for laziness reasons
class Button : public Interactive{
 public:
  /* target describes what happens after clicking down and up on the button
   * states[0] = neutral
   * states[1] = click
   * states[2] = hover */
  Button(Drawable * states[], void * target, bool screenTarget = true, void * (*myFunc)(void *) = NULL); 
  
  Drawable * states[NUM_STATES];
  Drawable * getImg(){return states[0];}
  void * changeState(int x, int y, int mouseClick, void * package = NULL);
  void draw(SDL_Surface * screen);
  bool screenTarget;
  bool useTargetAsPackage; //hackish solution, will fix later
  static const int neutral;
  static const int hover;
  static const int down;
  void * target;
};
#endif
