#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
struct names {
  char first[LEN];
  char last[LEN];
};

struct guy {
  struct names handle;
  char favfood[LEN];
  char job[LEN];
  float income;
};
int main(int argc, char *argv[]) {
  struct guy fellow[2] = {
      {{"Ewen", "Villard"}, "grilled salmon", "persionality coach", 168112.00},
      {{"John", "Doe"}, "steak", "software engineer", 120000.00}};
  struct guy *him;
  printf("address #1 %p #2: %p\n", &fellow[0], &fellow[1]);
  him = &fellow[0];
  printf("pointer #1: %p #2: %p\n", him, him + 1);
  printf("him->income is $%.2f: (*hime).income is $%.2f\n", him->income,
         (*him).income);
  him++;
  printf("him->favfood is %s: him->handle.last is %s\n", him->favfood,
         him->handle.last);
  return 0;
}