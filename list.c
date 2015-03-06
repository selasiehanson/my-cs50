#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include  "cs50.h"
#include "list.h"

node* first = NULL;

//prototypes
void delete(void);
void insert(void);
void search(void);
void traverse(void);

int main(int argc, char const *argv[]) {
  int c;

  do {
    printf("\nMENU\n\n"
    "1 - delete\n"
    "2 - insert\n"
    "3 - search\n"
    "4 - traverse\n"
    "0 - quit\n\n");

    printf("Command: ");
    c = GetInt();

    switch(c){
      case 1: delete(); break;
      case 2: insert(); break;
      case 3: search(); break;
      case 4: traverse(); break;
    }

  }while( c!= 0);

  node* ptr = first;
  while(ptr != NULL){
    node* predptr = ptr;
    ptr = ptr->next;
    free(predptr);
  }

  return 0;
}


void delete(void){

}

void insert(void){
  //insertion at three points head, tail and in-between
  printf("Enter a number: ");
  int n = GetInt();

  //create node
  node* newNode = malloc(sizeof(node));
  newNode->n= n;
  //we have an empty list
  if(first == NULL){
    newNode->next  = first;
    first = newNode;
    return;
  }

  node* prevPtr = NULL;
  node* currentTempPtr = first;

  while(currentTempPtr != NULL){

    if(currentTempPtr->n > n){
      if(prevPtr == NULL){
        first = newNode;
      }else {
        prevPtr->next = newNode;
      }
      newNode->next = currentTempPtr;
      return;
    }

    prevPtr = currentTempPtr;
    currentTempPtr = currentTempPtr->next;
  }

  if(currentTempPtr == NULL){
    //insert at tail
    newNode->next = NULL;
    prevPtr->next = newNode;
  }

}

void search(void){
  printf("Number to search for: ");

  int n = GetInt();

  node* ptr = first;

  while(ptr != NULL){
    if(ptr->n == n){
      printf("\nFound %i\n", n);
      sleep(1);
      break;
    }
    ptr = ptr->next;
  }
}

void traverse(void){
  node* ptr =  first;
  if(ptr == NULL) {
    printf("we have a  null\n");
  }
  while(ptr != NULL){
    printf("%i ", ptr->n);
    ptr = ptr->next;
  }
  printf("\n");
}
