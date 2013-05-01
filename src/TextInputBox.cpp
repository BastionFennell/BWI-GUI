#include "TextInputBox.h"

TextInputBox::TextInputBox(Drawable * inputBox, TTF_Font * myFont, SDL_Color myColor, void * (*myFunc)(void *)) : Interactive(myFunc){
  text = new Text(myFont, "", inputBox->position.x, inputBox->position.y, &myColor);
  box = inputBox;
}
std::string TextInputBox::getText(){
  return this->text->getText();
}
Drawable * TextInputBox::getImg(){
  return box;
}
void TextInputBox::draw(SDL_Surface * display){
  box->draw(display);
  text->draw(display);
}
void * TextInputBox::changeState(int x, int y, int click, void * package){
  //if(click == Interactive::clickDown)
  currentState = Interactive::clickDown;
  if(package != NULL){
    SDL_Event * input = static_cast<SDL_Event*>(package);
    if(input->type == SDL_KEYDOWN){
      char nextLetter = input->key.keysym.unicode;
      if(nextLetter == '\n')
	currentState = Interactive::clickUp;
      else if(nextLetter == 8)
	text->setText(text->getText().substr(0, text->getText().length() - 1));
      else if(nextLetter == '.' || nextLetter == ' '
	      || nextLetter == '?' || nextLetter == '!'
	      || nextLetter == ',' || nextLetter == '\''
	      || (nextLetter >= '0' && nextLetter <= '9')
	      || (nextLetter >= 'a' && nextLetter <= 'z')
	      || (nextLetter >= 'A' && nextLetter <= 'Z'))
	text->setText(text->getText() + nextLetter);
    }
  }
  return NULL;
}
