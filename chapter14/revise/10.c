#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct gas {
  float distance;
  float gals;
  float mpg;
};
struct gas set_mpg(struct gas gas) {
  gas.mpg = gas.distance / gas.gals;
  return gas;
}
void set_mpg2(struct gas *gas) { gas->mpg = gas->distance / gas->gals; }
int main(int argc, char *argv[]) {
  struct gas g = {20.2, 2.2};

  g = set_mpg(g);
  printf("%g\n", g.mpg);
  g.distance*=2;
  set_mpg2( &g);
  printf("%g\n", g.mpg);

  return 0;
}