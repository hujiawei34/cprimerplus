#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double add(double x, double y) { return x + y; }
double minus(double x, double y) { return x - y; }
double multiple(double x, double y) { return x * y; }
double divide(double x, double y) { return x / y; }
int main(int argc, char *argv[]) {
  double (*pf[4])(double, double) = {add, minus, multiple, divide};
  printf("%g\n", pf[1](10.0, 2.5));
  printf("%g\n", (*pf[1])(10.0, 2.5));

  return 0;
}