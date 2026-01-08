#include <stdio.h>
void func(double);
int main(void) {
  double n;
  printf("input n:");
  scanf("%lf", &n);
  func(n);
  return 0;
}
void func(double n) {
  n = n * n * n;
  printf("n=%.2f\n", n);
}