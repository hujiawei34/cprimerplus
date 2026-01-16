#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage:%s 2.0 2", argv[0]);
    return 1;
  }
  double base = strtod(argv[1], NULL);
  int exp = atoi(argv[2]);
  printf("%g^%d=%g\n",base,exp,pow(base, exp));

  return 0;
}