#include <stdio.h>
#include "cs50.h"

#define STUDENTS_COUNT 3

typedef struct {
  int id;
  string name;
  string house;
} student;



int main(int argc, char const *argv[]) {

  student students[STUDENTS_COUNT];

    for (int i = 0; i < STUDENTS_COUNT; i++) {
      printf("\nStudent Id Please: ");
      students[i].id = GetInt();
      printf("\nStudent name: ");
      students[i].name = GetString();
      printf("\nStudent house: ");
      students[i].house = GetString();
      printf("\n");
    }


  return 0;
}
