#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FUNDLEN 50
struct funds {
  char bank[FUNDLEN];
  double bankfund;
  char save[FUNDLEN];
  double savefund;
};
double sum(struct funds *fund) { return fund->bankfund + fund->savefund; }
int main(int argc, char *argv[]) {
  struct funds stan = {"Garlic-Melon Bank", 4032.27, "Luck's Savings and Loan",
                       8543.94};
  printf("Stan has a total of %.2f.\n", sum(&stan));
  return 0;
}