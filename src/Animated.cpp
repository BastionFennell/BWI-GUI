#include "Animated.h"

Animated::Animated(Drawable* images[], int numFrames, unsigned int frameDelay, int x, int y){
  this->images = new Drawable*[numFrames];
  for(int i = 0; i < numFrames; i++)
    this->images[i] = images[i];
  this->frameDelay = frameDelay;
  this->numFrames = numFrames;
  this->currentFrame = 0;
  this->position.x = x;
  this->position.y = y;
}
void Animated::draw(SDL_Surface * display){
  images[currentFrame]->draw(display);
  if(((SDL_GetTicks() % (frameDelay * numFrames)) / frameDelay) > currentFrame)
    currentFrame++;
}
