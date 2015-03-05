#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int add(int a, int b){
  return a + b;
}

void adder(){
  printf("Give me the first number: ");
  int a = GetInt();
  printf("Give me the second number: ");
  int b = GetInt();
  printf("The sum of %i and %i is %i\n", a,b, add(a,b));
}

void messager(){
  string message = "Welcome to XMH Rocking Server......";
  printf("%s\n",message);

  printf("What is your name\n");
  string name = GetString();
  printf("Hello %s, you are logged in\n", name);
}

void floatCraziness(){
  float x = (float) 1 / 10;
  printf("%.2f\n", x);
}

void string_madness(){
  printf("Enter some text: ");
  string str = GetString();
  for(int i=0; i < strlen(str); ++i){
    printf("%c\n", str[i]);
  }
}

void capitalize(){
  printf("Enter text to capitalize: ");
  string s = GetString();

  for(int i=0, n= strlen(s); i < n; i++){
    printf("%c",toupper(s[i]));
  }

  printf("\n");
}

string rot13(string str){
  int n = strlen(str);
  for(int i=0; i < n; i++){
    if(str[i] > ('a' - 1) && str[i] < ('z' + 1)){
      if(str[i] > (('a' - 1) + 13)){
        str[i] = str[i] - 13;
      }else {
        str[i] = str[i] + 13;
      }
    }else if(str[i] > ('A' - 1) && str[i] < ('Z' + 1)){
      if(str[i] > (('A' -1) + 13)){
        str[i] = str[i] - 13;
      }else {
        str[i] = str[i] + 13;
      }
    }
  }
  return str;
}

void test_rot13(){
  printf("Enter some string to encrypted: ");
  string str = GetString();
  printf("You Entered %s\n", str);
  printf("Encrypted as: %s\n",rot13(str));

}

int main (){

  // adder();
  // floatCraziness();
  //string_madness();
  // capitalize();
  // test_rot13();
  printf("%d\n", (27 % 26));
  return 0;
}
