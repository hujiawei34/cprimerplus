#include "../../my.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};
int main(int argc, char *argv[]) {
  struct book library[MAXBKS];
  int count = 0;
  int index;

  
  printf("please enter the book title.\n");
  printf("press [enter] at the start of a line to quit.\n");
  while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
         library[count].title[0] != '\0') {
    printf("Now enter the author.\n");
    s_gets(library[count].author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library[count].value);
    while (getchar() != '\n')
      ;
    if (count < MAXBKS)
      printf("Enter the next tile.\n");
  }
  if (count > 0) {
    printf("Here is the list of your books:\n");
    for (index = 0; index < count; index++)
      printf("%s by %s:$%.2f\n", library[index].title, library[index].author,
             library[index].value);

  } else {
    printf("No books?Too bad.\n");
  }

  return 0;
}