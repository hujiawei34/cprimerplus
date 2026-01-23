#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MONTHS 12
struct month {
  char name[10];
  char brev[4];
  int days;
  int index;
};
void print_months(struct month *);
struct month *get_months(void);
int get_input(void);
void get_days(struct month *months, int n);

int main(int argc, char *argv[]) {

  struct month *months = get_months();
  int input;
  while ((input = get_input()) != -1) {
    get_days(months, input);
  }
  free(months);
  printf("Done.\n");
  return 0;
}
void get_days(struct month *months, int n) {
  int days=0;
  for(int i=0;i<n;i++){
    days+=months[i].days;
  }
  printf("end to %s,all days are %d .\n",months[n-1].name,days);
}
int get_input(void) {
  int index;
  printf("Enter a month number (1-12): ");
  int status = scanf("%d", &index);
  while (getchar() != '\n')
    continue;
  if (status != 1 || index < 1 || index > 12) {
    return -1;
  }
  return index;
}
struct month *get_months() {
  struct month *months = malloc(MONTHS * sizeof(struct month));

  struct month inited_months[MONTHS] = {
      {"January", "Jan", 31, 0},   {"February", "Feb", 28, 1},
      {"March", "Mar", 31, 2},     {"April", "Apr", 30, 3},
      {"May", "May", 31, 4},       {"June", "Jun", 30, 5},
      {"July", "Jul", 31, 6},      {"August", "Aug", 31, 7},
      {"September", "Sep", 30, 8}, {"October", "Oct", 31, 9},
      {"November", "Nov", 30, 10}, {"December", "Dec", 31, 11}};
  for (int i = 0; i < MONTHS; i++) {
    strcpy(months[i].name, inited_months[i].name);
    strcpy(months[i].brev, inited_months[i].brev);
    months[i].days = inited_months[i].days;
    months[i].index = inited_months[i].index;
  }
  return months;
}
void print_months(struct month *months) {
  int index;
  for (index = 0; index < MONTHS; index++)
    printf("%s %s %d %d\n", months[index].name, months[index].brev,
           months[index].days, months[index].index);
}