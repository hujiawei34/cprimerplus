#include "../../my.h"
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
struct input {
  int day;
  struct month month_t;
  int year;
  bool succes;
};
struct input get_input();
struct month *get_months();
int calc_days(struct input in);
void strtolower(char *str);
int main(int argc, char *argv[]) {
  struct input in = get_input();
  while (in.succes) {
    printf("end to %d-%d-%d,total day:%d\n", in.year, in.month_t.index + 1,
           in.day, calc_days(in));
    in = get_input();
  }

  return 0;
};
void strtolower(char *str) {
  while (*str != '\0') {
    if (isupper(*str)) {
      *str = tolower(*str);
    }
    str++;
  }
}

struct input get_input() {
  struct input in;

  printf("input day:");
  scanf("%2d", &in.day);
  while (getchar() != '\n')
    ;
  if (in.day < 1 || in.day > 31) {
    puts("invalid daynumber,exceed 1~31");
    exit(1);
  }

  printf("input month:");
  char month_input[10];
  s_gets(month_input, 10);
  bool all_number = true;
  for (int i = 0; i < 10 && month_input[i] != '\0'; i++) {
    if (!isdigit(month_input[i])) {
      all_number = false;
    }
  }
  struct month *months = get_months();
  if (all_number) {
    int index = atoi(month_input);
    if (index < 1 || index > 12) {
      printf("invalid month number,number exceed 1~12\n");
      exit(1);
    }
    in.month_t = months[index - 1];
  } else {
    int i = 0;
    strtolower(month_input);
    for (int i = 0; i < MONTHS; i++) {
      strtolower(months[i].name);
      strtolower(months[i].brev);
      if (strcmp(month_input, months[i].name) == 0 ||
          strcmp(month_input, months[i].brev)) {
        break;
      }
    }
    if (i < MONTHS) {
      in.month_t = months[i];
    } else {
      printf("invalid month name or brev\n");
      exit(1);
    }
  }

  printf("input year:");
  scanf("%4d", &in.year);
  while (getchar() != '\n')
    ;

  if (in.year < 1000 || in.year > 9999) {
    puts("invalid year number,exceed 1000~9999");
    exit(1);
  }
  in.succes = true;
  return in;
}

int calc_days(struct input in) {
  struct month *months = get_months();
  bool is_run = false;
  if (in.year % 100 == 0) {
    if (in.year % 400 == 0)
      is_run = true;
  } else if (in.year % 4 == 0)
    is_run = true;
  if (is_run) {
    months[1].days = 29;
  }
  int sum = 0;
  for (int i = 0; i < in.month_t.index; i++) {
    sum += months[i].days;
  }
  sum += in.day;
  return sum;
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