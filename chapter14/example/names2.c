#include "../../my.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NLEN 30
struct namect {
  char fname[NLEN];
  char lname[NLEN];
  int letters;
};
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

int main(int argc, char *argv[]) {
  struct namect person;
  person = getinfo();
  person = makeinfo(person);
  showinfo(person);

  return 0;
}
struct namect getinfo() {
  struct namect person;
  printf("Please enter your first name:\n");
  s_gets(person.fname, NLEN);
  printf("Now enter your last name:\n");
  s_gets(person.lname, NLEN);
  return person;
}
struct namect makeinfo(struct namect person) {
  person.letters = strlen(person.fname) + strlen(person.lname);
  return person;
}
void showinfo(struct namect person) {
  printf("%s %s ,your name has %d letters.\n", person.fname, person.lname,
         person.letters);
}