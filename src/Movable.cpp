#include "Movable.h"
Movable::Movable(Drawable * img):x(-1),y(-1){
  image = img;
  this->currentState = Interactive::holdState;
}
void * Movable::changeState(int x, int y, int click, void * package){
  if(click == Interactive::clickUp)
    this->currentState = Interactive::clickUp;
  else{
    if(this->currentState == Interactive::clickDown){
      image->changePosition(x - this->x, y - this->y);
      this->x = x;
      this->y = y;
    }
    if(image->inRectangle(x, y)){
      if(click == Interactive::clickDown || (this->currentState == Interactive::clickDown && click == Interactive::holdState)){
	this->x = x;
	this->y = y;
	this->currentState = Interactive::clickDown;
      }
      //else
      //this->currentState = Interactive::clickUp;
    }
  }
  return NULL;
}
void Movable::draw(SDL_Surface * display){
  image->draw(display);
}
