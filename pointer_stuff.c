#include <stdio.h>
#include "cs50.h"


int main(){
  printf("State your name: ");

  string name = GetString();

  printf("%s", name );

  free(name);
  return 0;
}
