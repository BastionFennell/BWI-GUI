#include "Sprite.h"

const int Sprite::clickDown = 0;
const int Sprite::clickUp = 1;
const int Sprite::hold = 2;

Sprite::Sprite(std::string fileName, int xpos, int ypos) : click(false){
  img = new SDL_Surface*;
  loadImages(fileName);
  edge = new SDL_Rect*;
  (*edge) = new SDL_Rect;
  (*edge)->x = xpos;
  (*edge)->y = ypos;
  (*edge)->w = (*img)->w;
  (*edge)->h = (*img)->h;
}
bool Sprite::loadImages(std::string fileName){
  //Drawable::loadImages(fileName);
  SDL_Surface * temp = IMG_Load(fileName.c_str());
  *img = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  return true;
}
void Sprite::draw(SDL_Surface * screen){
  SDL_BlitSurface(*img, NULL, screen, *edge);
}
void Sprite::changePosition(int x, int y, int state){
  if(state == clickDown
     && (x >= (*edge)->x && x <= ((*edge)->x + (*edge)->w))
     && (y >= (*edge)->y && y <= ((*edge)->y + (*edge)->h))){
    this->x = x;
    this->y = y;
    click = true;
  }
  if(state == clickUp)
    this->click = false;
  if(click){
    (*edge)->x += x - this->x;
    (*edge)->y += y - this->y;
    this->x += x - this->x;
    this->y += y - this->y;
    }
}

Sprite::~Sprite(){
  SDL_FreeSurface(*img);
  delete *edge;
  delete edge;
  delete img;
}
