#include "Screen.h"

Screen::Screen(){} //empty default constructor

Screen * Screen::addItem(Drawable * item){
  drawableItems.push_back(item);
  return this;
}
Screen * Screen::addItem(Interactive * item){
  interactiveItems.push_back(item);
  return this;
}
