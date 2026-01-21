#include "../../my.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 30
enum spectrum { red, orange, yellow, green, blue, violet };
const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};
int main(int argc, char *argv[]) {
  char choice[LEN];
  enum spectrum color;
  bool color_is_found = false;

  puts("Enter a color:(empty line to quit):");
  while (s_gets(choice, LEN) != NULL && choice[0] != '\0') {
    for (color = red; color <= violet; color++) {
      if (strcmp(choice, colors[color]) == 0) {
        color_is_found = true;
        break;
      }
    }
    if (color_is_found)
      switch (color) {
      case red:
        printf("Roses are red.\n");
        break;
      case orange:
        printf("Poppies are orange.\n");
        break;
      case yellow:
        printf("Sunflowers are yellow.\n");
        break;
      case green:
        printf("Grass is green.\n");
        break;
      case blue:
        printf("Bluebells are blue.\n");
        break;
      case violet:
        printf("Violets are violet.\n");
        break;
      }
    else
     printf("i don't know about the color %s.\n",choice);
    color_is_found = false;
    puts("Enter next color:(empty line to quit):");
  }
  puts("Goodbye!");
  return 0;
}