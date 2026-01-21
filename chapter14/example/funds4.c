#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FUNDLEN 50
#define N 2
struct funds
{
  char bank[FUNDLEN];
  double bankfund;
  char save[FUNDLEN];
  double savefund;
};
double sum(const struct funds fund[], int n)
{
  double tot = 0;
  for (int i = 0; i < n; i++)
  {
    tot += fund[i].bankfund + fund[i].savefund;
  }
  return tot;
}
int main(int argc, char *argv[])
{
  struct funds jone[N] = {
      {"Garlic-Melon Bank",
       4032.27,
       "Luck's Savings and Loan",
       8543.94},
      {"Honet Jack's Bank",
       3620.88,
       "Party Time Savings",
       3802.91}};

  printf("Stan has a total of %.2f.\n", sum(jone, N));
  return 0;
}