#include <stdio.h>
void func_d(void);

int main(void) {
  // a.
  int x = 1;
  x--;
  printf("%d\n", x);

  // b.
  int n, m, k;
  n = 10, k = 3;
  m = n % k;
  printf("%d\n", m);

  // c.
  int q, b, a, p;
  q = 100, b = 10, a = 2;
  p = q / b - a;
  printf("%d\n", p);

  //d.
  func_d();
  return 0;
}
void func_d(void) {
  float a, b, c, d, x;
  a = 10, b = 200, c = 3, d = 4;
  x = (a + b) / (c * d);
  printf("%f\n", x);
}