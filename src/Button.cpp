#include "Button.h"

const int Button::neutral = 0;
const int Button::down = 1;
const int Button::hover = 2;

Button::Button(Drawable * img[], void * target, bool screenTarget, void * (*myFunc)(void *)):Interactive(myFunc){
  this->screenTarget = screenTarget;
  this->useTargetAsPackage = !screenTarget;
  this->target = target;
  currentState = neutral;
  for(int i = 0; i < NUM_STATES; i++)
    states[i] = img[i];
}
void * Button::changeState(int x, int y, int mouseClick, void * package){
  if(states[currentState]->inRectangle(x, y) && currentState == down){
    currentState = hover;
   
    if(package == NULL || useTargetAsPackage)
      package = target;
    if(myFunction)
	myFunction(package);
    return screenTarget ? target : NULL;
  }
  else if(states[currentState]->inRectangle(x, y) && mouseClick == Interactive::clickDown){
    currentState = down;
}
  if(!states[currentState]->inRectangle(x, y)){
    currentState = neutral;
  }
  return NULL;
}
void Button::draw(SDL_Surface * screen){
  states[currentState]->draw(screen);
}
