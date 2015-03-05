#include "cs50.h"
#include <stdio.h>

int sigma(int);
int sigma_alt(int);
int sigma_rec(int);

int main(void){

  int n;
  do {
    printf("Positive number please: ");
    n = GetInt();
  }while(n < 1);

  int answer = sigma_rec(n);
  printf("%i\n", answer);
  return 0;
}

int sigma(int n){
  if(n < 1){
    return 0;
  }

  int sum = 0;
  for(int i=1; i <= n; ++i){
    sum += i;
  }
  return sum;
}

int sigma_alt(int n){
  int sum = 0;
  while(n > 0){
    sum += n;
    n -= 1;
  }
  return sum;
}

int sigma_rec(int n){
  if( n <= 0){
    return 0;
  }else {
    return n + sigma_rec(n - 1);
  }
}
