#include "GuiScreen.h"

template<typename T>
bool compare(T lhs, T rhs){
  return lhs->priority < rhs->priority;
}

Screen * GuiScreen::draw(SDL_Surface * display){
  SDL_Event      event;
  int            x;
  int            y;
  Screen *       next = NULL;
  TTF_Font *     myFont = TTF_OpenFont("resources/Inconsolata.ttf", 30);
  SDL_Color      myColor;
  myColor.r = 20;
  myColor.g = 200;
  myColor.b = 150;
  SDL_EnableUNICODE(1);
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL); // backspace hold down
  while(true){
    if(SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_QUIT:
	return NULL;
      case SDL_MOUSEMOTION:
	SDL_GetMouseState(&x, &y);
	for(unsigned int i = 0; i < interactiveItems.size(); i++){
	  next = static_cast<Screen*>(interactiveItems.at(i)->changeState(x, y, Interactive::holdState, &event));
	  if(next != NULL)
	    return next;
	}
	break;
      case SDL_MOUSEBUTTONDOWN:
	if(event.button.button == SDL_BUTTON_LEFT){
	  for(unsigned int i = 0; i < interactiveItems.size(); i++){
	    if(interactiveItems.at(i)->getImg()->inRectangle(x, y)){
	      next = static_cast<Screen*>(interactiveItems.at(i)->changeState(event.button.x, event.button.y, Interactive::clickDown, &event));
	      if(next)
		return next;
	      i += interactiveItems.size(); //fix this later
	    }
	  }
	}
	break;
      case SDL_MOUSEBUTTONUP:
	if(event.button.button == SDL_BUTTON_LEFT){
	  for(unsigned int i = 0; i < interactiveItems.size(); i++){
	    next = static_cast<Screen*>(interactiveItems.at(i)->changeState(event.button.x, event.button.y, Interactive::clickUp, &event));
	    if(next != NULL)
	      return next;
	  }
	}
	break;
      case SDL_KEYDOWN:
	for(unsigned int i = 0; i < interactiveItems.size(); i++)
	  interactiveItems.at(i)->changeState(event.button.x, event.button.y, Interactive::holdState, &event);
	switch(event.key.keysym.sym){
	case SDLK_ESCAPE:
	  return NULL;
	  break;
	default:
	  break;
	}
      }
    }
    //std::sort(drawableItems.begin(), drawableItems.end(), compare<Drawable*>);
    //std::sort(interactiveItems.begin(), interactiveItems.end(), compare<Interactive*>);

    for(std::vector<Drawable*>::iterator it = drawableItems.begin(); it !=drawableItems.end(); it++){
      (*it)->draw(display);
    }
    for(std::vector<Interactive*>::iterator it = interactiveItems.begin(); it != interactiveItems.end(); it++){
      (*it)->draw(display);
    }
    SDL_Flip(display);
    SDL_FreeSurface(display);
  }
  return NULL;
}
