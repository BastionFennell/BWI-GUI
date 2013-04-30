#include "Picture.h"
Picture::Picture(std::string fileName, int x, int y):Drawable(x, y){
  this->priority = 7;
  SDL_Surface * temp = IMG_Load(fileName.c_str());
  image = SDL_DisplayFormatAlpha(temp);
  SDL_FreeSurface(temp);
  setDimensions(image->w, image->h);
}
void Picture::draw(SDL_Surface * display){
  SDL_BlitSurface(image, NULL, display, &position);
}
