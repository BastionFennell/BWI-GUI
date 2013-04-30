EVERYTHING has been changed (almost)
Version 0.2 of the GUI is up! It is better than version 0.1!

insert licensing rights open source etc...

I don't know how the legal stuff works, please don't sue me

This program requires SDL, if the makefile doesn't work, substitute in the results of 

sdl-config --cflags --libs

in the SDL configuration subsection of the makefile

There is some issue with SDL_ttf that installs it in a different location than the rest of SDL. You can remedy this by copying the header file into the correct directory and the shared libraries into the correct directory (there are 5 or so of the shared libraries)

TO BUILD
make
TO RUN
make run
TO GDB
make debug
TO REBUILD
make rebuild


Next on the list:
     Scrollable List

Documentation (incomplete):

Inheritance tree:
Interactive (composed of drawable(s) + methods)
   Button
   Movable
Drawable
   Picture
   Screen
   Sprite
   Text
Screen
   GuiScreen


Button:
   Button(Drawable * states[], Screen * target, void * (*myFunc)(void *) = NULL)
   states[0] = neutral
   states[1] = on click
   states[2] = on hover
   states[] contains pointers to drawable objects (IE: picture)
   Example:
   #include <Button.h>
   Button myButton(myPictures, myTarget, &foo);

   target is a pointer to the screen that is brought up upon button click (may change soon)
   foo is a pointer to the function that is called upon button click
 ---  
   Screen * changeState(int x, int y, int mouseClick, void * package = NULL);
   package is passed into foo.
   x and y are mouse coordinates
   mouseClick corresponds to the state of the mouse (check Interactive.h/cpp)
