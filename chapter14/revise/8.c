#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct fullname {
  char fname[20];
  char lname[20];
};
struct bard {
  struct fullname name;
  int born;
  int died;
};
int main(int argc, char *argv[]) {
  struct bard willie;
  struct bard *pt = &willie;
  // a.
  willie.born;
  // b.
  pt->born;
  // c.
  scanf("%d", &willie.born);
  // d.
  scanf("%d", &pt->born);
  // e.
  scanf("%s", willie.name.lname);
  // f.
  scanf("%s", pt->name.lname);
  // g.
  char c = willie.name.fname[2];
  // e.
  int n = strlen(willie.name.fname) + strlen(willie.name.lname);
  return 0;
}