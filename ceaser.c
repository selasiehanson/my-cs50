#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"

string rot(string str, int key){
  key = key % 26;
  int n = strlen(str);
  for(int i=0; i < n; i++){
    if(str[i] > ('a' - 1) && str[i] < ('z' + 1)){
      if(str[i] > (('a' - 1) + key)){
        str[i] = str[i] - key;
      }else {
        str[i] = str[i] + key;
      }
    }else if(str[i] > ('A' - 1) && str[i] < ('Z' + 1)){
      if(str[i] > (('A' -1) + key)){
        str[i] = str[i] - key;
      }else {
        str[i] = str[i] + key;
      }
    }
  }
  return str;
}

int main(int argc, string argv[]){
  if(argc != 2){
    printf("Wrong ussage: program should be run as ceaser <key>, eg: ceaser 10");
    return 1;
  }

  int key = atoi(argv[1]);

  printf("Welcome to CEASER CIPHER\n");
  printf("Please enter some text to encrypt: ");
  string text = GetString();
  printf("Encrypted with key= %i as %s", key, rot(text, key));
  return 0;
}
