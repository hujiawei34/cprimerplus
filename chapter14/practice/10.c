#include "../../my.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void chop(char *str);
void eat(char *str);
void play(char *str);
void sleep(char *str);
void hang(char *str);
void show_menu(void);
int get_choice(void);
int main(int argc, char *argv[]) {
  void (*pf[5])(char *str) = {chop, eat, play, sleep, hang};
  puts("welcome to my word!");
  puts("what's your name?");
  char name[20];
  s_gets(name, 20);
  printf("hello, %s!what you want to do?\n", name);
  show_menu();
  int choice = get_choice();
  while (choice != -1) {
    pf[choice - 1](name);
    show_menu();
    choice = get_choice();
  }
  return 0;
}
void show_menu(void) {
  printf("1. chop\n");
  printf("2. eat\n");
  printf("3. play\n");
  printf("4. sleep\n");
  printf("5. hang\n");
  printf("-1. exit\n");
}
int get_choice(void) {
  int choice;
  int status = scanf("%d", &choice);
  while (getchar() != '\n')
    continue;
  while (status != 1 || choice < -1 || choice > 5) {
    printf("invalid choice, please input again:");
    status = scanf("%d", &choice);
    while (getchar() != '\n')
      continue;
  }
  return choice;
}
void chop(char *str) { printf("%s is chopping.\n", str); }
void eat(char *str) { printf("%s is eating.\n", str); }
void play(char *str) { printf("%s is playing.\n", str); }
void sleep(char *str) { printf("%s is sleeping.\n", str); }
void hang(char *str) { printf("%s is hanging.\n", str); }
