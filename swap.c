#include <stdio.h>

void swap(int *, int *);

int main(int argc, char const *argv[]) {
  int ret = 0;
  int a = 9, b =20;
  printf("Before SWap: a is %d and b is %d\n", a , b);
  swap(&a,&b);
  printf("AftterSWAP:  a is %d and b is %d\n", a , b);

  return ret;
}


void swap(int* a,int* b ){
  int temp = *a;
  *a = *b;
  *b = *a;
}
