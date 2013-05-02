#include "TextInputBox.h"

TextInputBox::TextInputBox(Drawable * inputBox, TTF_Font * myFont, SDL_Color myColor, void * (*myFunc)(void *)) : Interactive(myFunc){
  maxChars = 999999;
  currentLine = 0;
  full = false;
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
  currentState = Interactive::clickDown;
  int height;
  int width;
  if(package != NULL){
    SDL_Event * input = static_cast<SDL_Event*>(package);
    if(input->type == SDL_KEYDOWN){
      char nextLetter = input->key.keysym.unicode;
      if(nextLetter == 8){
	full = false;
	//case 1: we're just in a line and no newline before us
	//case 2: we're at the beginning of a line and the previous line is full
	//case 3: we're at the beginning of a line and the previous line is not full
	if(currentLine <= maxChars){
	  if(text->getText()[text->getText().length() - 1] == '\n')
	    text->setText(text->getText().substr(0, text->getText().length() - 1));
	  text->setText(text->getText().substr(0, text->getText().length() - 1));
	  int i = text->getText().length() - 1;
	  currentLine = 0;
	  while(text->getText()[i] != '\n' && i >= 0){
	    currentLine++;
	    i--;
	  }
	}
      }
      else if(nextLetter == '.' || nextLetter == ' '
	      || nextLetter == '?' || nextLetter == '!'
	      || nextLetter == ',' || nextLetter == '\''
	      || (nextLetter >= '0' && nextLetter <= '9')
	      || (nextLetter >= 'a' && nextLetter <= 'z')
	      || (nextLetter >= 'A' && nextLetter <= 'Z')){
	TTF_SizeText(text->font, (text->getText() + nextLetter).c_str(), &width, &height);
	if(maxChars == 999999){
	  if(width > box->position.w)
	    maxChars = text->getText().length() - 2;
	}
	if(currentLine < maxChars && !full){
	  currentLine++;
	  text->setText(text->getText() + nextLetter);
	}
	else{
	  if((text->getLines() + 1) * (height + 1) > box->position.h)
	    full = true;
	  if(!full){
	    currentLine = 0;
	    text->setText(text->getText() + '\n' + nextLetter);
	  }
	}
      }
      else if(input->key.keysym.sym == SDLK_RETURN){
	currentLine = 0;
	text->setText(text->getText() + '\n');
      }
    }
  }
  return NULL;
}
