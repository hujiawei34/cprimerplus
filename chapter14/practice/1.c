#include "../../my.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MONTHS 12
#define INPUT_LEN 20
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
void strtolower(char *str);

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
  int days = 0;
  for (int i = 0; i < n; i++) {
    days += months[i].days;
  }
  printf("end to %s,all days are %d .\n", months[n - 1].name, days);
}
int get_input(void) {
  int index = -1;
  printf("input month name (empty line to quit):");
  char *input = malloc(INPUT_LEN * sizeof(char));
  s_gets(input, INPUT_LEN);
  struct month *months = get_months();
  while (input[0] != '\0') {
    for (int i = 0; i < MONTHS; i++) {
      strtolower(months[i].name);
      strtolower(input);
      if (strcmp(months[i].name, input)==0) {
        return months[i].index+1;
      }
    }
  }
  free(input);
  return index;
}
void strtolower(char *str) {
  while (*str != '\0') {
    *str = tolower(*str);
    str++;
  }
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