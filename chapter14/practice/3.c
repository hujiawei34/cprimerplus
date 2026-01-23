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
char *s_gets_fp(char *s, int n, FILE *fp) {
  char *ret_val;
  int i = 0;
  ret_val = fgets(s, n, fp);
  if (ret_val) {
    char *find = strchr(s, '\n');
    if (find)
      *find = '\0';
    else
      while (getc(fp) != '\n' && !feof(fp))
        continue;
  }
  return ret_val;
}
int main(int argc, char *argv[]) {
  struct book library[MAXBKS];
  int count = 0;
  int index;
  FILE *fp;
  fp = fopen("books.txt", "r");

  printf("please enter the book title.\n");
  printf("press [enter] at the start of a line to quit.\n");
  while (count < MAXBKS &&
         s_gets_fp(library[count].title, MAXTITL, fp) != NULL &&
         library[count].title[0] != '\0') {
    printf("Now enter the author.\n");
    s_gets_fp(library[count].author, MAXAUTL, fp);
    printf("Now enter the value.\n");
    fscanf(fp, "%f", &library[count].value);
    while (getc(fp) != '\n' && !feof(fp))
      ;
    count++;
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
