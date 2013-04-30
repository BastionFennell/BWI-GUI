#include "Interactive.h"

const int Interactive::clickDown = 0;
const int Interactive::clickUp   = 1;
const int Interactive::holdState  = 2;

Interactive::Interactive(void * (*myFunc)(void *)):priority(5){
  myFunction = myFunc;
}
void Interactive::setPriority(int x){priority = x;}
bool Interactive::operator<(const Interactive & rhs){return priority<rhs.priority;}
