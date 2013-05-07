#include <iostream>
#include <string>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Drawable.h"
#include "Interactive.h"
#include "Button.h"
#include "Movable.h"
#include "Screen.h"
#include "Text.h"
#include "Picture.h"
#include "GuiScreen.h"
#include "TextInputBox.h"
#include "GUI_ROS.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

ros::Publisher output_pub;

void * foo(void * package){
  std::cout << "Hello World\n";
  return NULL;
}
//TODO fix this method derp!
void * foo2(void * package){
  std_msgs::String outputText;
  outputText.data = static_cast<TextInputBox*>(package)->getText();
  rosPublish(output_pub, outputText);
  return NULL;
}
int main(int argc, char **argv){
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("BWI", "BWI");
  SDL_Surface * display = SDL_SetVideoMode(VIDEO_WIDTH, VIDEO_HEIGHT, 0, SDL_DOUBLEBUF);
  TTF_Init();
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  output_pub = n.advertise<std_msgs::String>("audio_say", 1000);
  Drawable ** animatedFrames = new Drawable*[5];
  Screen * myScreen;
  Screen * mapScreen;
  Screen * speechScreen;
  Screen * currentScreen;
  Screen * nextScreen;
  Drawable * button1[3];
  Drawable * button2[3];
  Drawable * button3[3];
  Drawable * button4[3];
  Drawable * returnButton[3];
  Drawable * speechButton[3];
  Drawable * inputBox = new Picture("resources/inputBox.png", VIDEO_WIDTH / 6, VIDEO_HEIGHT / 4);
  Picture * myBackground = new Picture("resources/1.png", 0, 0);
  Picture * myBackground2 = new Picture("resources/2.png", 0, 0);
  Picture * map = new Picture("resources/map.png", VIDEO_WIDTH / 6, VIDEO_HEIGHT / 6);
  TTF_Font * myFont = TTF_OpenFont("resources/Inconsolata.ttf", 20);
  SDL_Color myColor;
  myColor.r = 0;
  myColor.g = 0;
  myColor.b = 0;
  TextInputBox * myInput = new TextInputBox(inputBox, myFont, myColor, NULL);
  Text * myText1 = new Text(myFont, "Map", VIDEO_WIDTH / 4 - 50, VIDEO_HEIGHT / 2, &myColor);
  Text * myText2 = new Text(myFont, "Speech", VIDEO_WIDTH / 2 + 250, VIDEO_HEIGHT / 2, &myColor);
  button1[0] = new Picture("resources/mapButton.png", VIDEO_WIDTH / 6, VIDEO_HEIGHT / 4);
  button1[1] = new Picture("resources/mapButton.png", VIDEO_WIDTH / 6, VIDEO_HEIGHT / 4);
  button1[2] = new Picture("resources/mapButton.png", VIDEO_WIDTH / 6, VIDEO_HEIGHT / 4);  
  button2[0] = new Picture("resources/speechButton.png", VIDEO_WIDTH * 4 / 6, VIDEO_HEIGHT / 4 );
  button2[1] = new Picture("resources/speechButton.png", VIDEO_WIDTH * 4 / 6, VIDEO_HEIGHT / 4);
  button2[2] = new Picture("resources/speechButton.png", VIDEO_WIDTH * 4 / 6, VIDEO_HEIGHT / 4);

  returnButton[0] = new Picture("resources/backArrow.png", 50, VIDEO_HEIGHT - 200);
  returnButton[1] = new Picture("resources/backArrow.png", 50, VIDEO_HEIGHT - 200);
  returnButton[2] = new Picture("resources/backArrow.png", 50, VIDEO_HEIGHT - 200);

  speechButton[0] = new Picture("resources/speak.png", 300, VIDEO_HEIGHT - 150);
  speechButton[1] = new Picture("resources/speak.png", 300, VIDEO_HEIGHT - 150);
  speechButton[2] = new Picture("resources/speak.png", 300, VIDEO_HEIGHT - 150);
  
  if(button1[0] == NULL || button1[1] == NULL || button1[2] == NULL)
    std::cout << "failed to load images\n";
  myScreen = new GuiScreen;
  mapScreen = new GuiScreen;
  speechScreen = new GuiScreen;
  Button * myReturnButton = new Button(returnButton, myScreen, &foo);
  Button * myButton1 = new Button(button1, mapScreen);
  Button * myButton2 = new Button(button2, speechScreen);
  Button * speech = new Button(speechButton, myInput, false, &foo2);
  myScreen->addItem(myButton1)->addItem(myButton2)->addItem(myBackground)->addItem(myText1)->addItem(myText2); //->addItem(myText3)->addItem(myText4)->addItem(myButton3)->addItem(myButton4)
  mapScreen->addItem(myReturnButton)->addItem(myBackground)->addItem(map);
  speechScreen->addItem(myReturnButton)->addItem(myBackground)->addItem(speech)->addItem(myInput);
  std::cout << myInput << std::endl;
  currentScreen = myScreen;
  nextScreen = NULL;
  while(true){
    nextScreen = currentScreen->draw(display);
    if(nextScreen == NULL)
      break;
    else if(nextScreen != NULL){
      for(unsigned int i = 0; i < currentScreen->interactiveItems.size(); i++)
	currentScreen->interactiveItems.at(i)->currentState = Interactive::holdState;
      currentScreen = (Screen*)nextScreen;
      nextScreen = NULL;
    }
  }
  SDL_Quit();
  return 0;
}
