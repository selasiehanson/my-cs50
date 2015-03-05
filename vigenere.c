#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cs50.h"

int findVal(char c){
  int val;
  if(islower(c)){
    val  = ( c- 97) % 25;
  }else{
    val = ( c- 65) % 25;
  }
  return val;
}

string vigenere_encrypt(string str, string key){
    int n = strlen(str);
    int keyLength = strlen(key);
    int nextIdx = 0;

    //we translate everything to index 0 and add the correction later
    for(int i=0; i < n; ++i){
      if(islower(str[i])){
        str[i] = ((str[i] - 'a') + findVal(key[nextIdx])) % 26 ; //translate to zero
        str[i] = str[i] + 'a'; //correction
      }else if(isupper(str[i])){
        str[i] = ((str[i] - 'A') + findVal(key[nextIdx])) % 26 ;
        str[i] = str[i] + 'A';
      }else{
        continue;
      }

      nextIdx++;
      if(nextIdx > (keyLength - 1)){
        nextIdx = 0;
      }
    }

  return str;
}


int main(int argc, string argv[]){

  if(argc != 2){
    printf("Wrong ussage: program should be run as ceaser <key>, eg: vigenere 10\n");
    return 1;
  }

  string key = argv[1];

  printf("Welcome to Vigenere Cipher.....\n");
  printf("Please enter some text to encrypt: ");
  string text = GetString();
  printf("You entered `%s`\n", text);
  printf("Encrypted with key= %s becomes %s\n", key, vigenere_encrypt(text, key));
  return 0;

}
