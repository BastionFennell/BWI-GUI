#include "Text.h"

Text::Text(TTF_Font * myFont, std::string message, int x, int y, SDL_Color * color) : Drawable(x, y){
  this->priority = 7;
  if(~TTF_WasInit() && TTF_Init() == -1)
    std::cerr << "Failure to initialize truetype font interface" << std::endl;
  this->font = myFont;
  this->color.r = color->r;
  this->color.g = color->g;
  this->color.b = color->b;
  setText(message);
}
void Text::setText(std::string text){
  myText = text;
  int n = 0;
  std::vector<std::string> textLines;
  std::string substring = text;
  while(n != std::string::npos){
    n = substring.find('\n', 0);
      textLines.push_back(substring.substr(0, n));
      substring = substring.substr(n + 1, std::string::npos);
  }
  numLines = textLines.size();
  image.clear();
  for(unsigned int i = 0; i < textLines.size(); i++)
    image.push_back(TTF_RenderText_Blended(font, textLines.at(i).c_str(), color));
  int wtemp, w = 0;
  for(unsigned int i = 0; i < textLines.size(); i++){
    TTF_SizeText(this->font, textLines.at(i).c_str(), &wtemp, NULL);
    if(wtemp > w)
      w = wtemp;
	}
  int h = 10;
  lineSkip = TTF_FontLineSkip(font);
  h = (textLines.size() - 1) * lineSkip + h;
  setDimensions(w, h);
}
int Text::getLines(){
  return numLines;
}
void Text::draw(SDL_Surface * display){
  SDL_Rect temp;
  for(unsigned int i = 0; i < image.size(); i++){
    temp.x = this->position.x;
    temp.y = this->position.y + i * lineSkip;
    temp.w = 500;
    temp.h = 500;
    SDL_BlitSurface(image.at(i), NULL, display, &temp);
  }
}
std::string Text::getText(){
  return myText;
}
