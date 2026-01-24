#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
double double_sqrt(double x) {
  return sqrt(sqrt(x));
}
double double_cbrt(double x) {
  return cbrt(cbrt(x));
}
void transform(double src[],double dst[],int n,double (*pf)(double))
{
  for (int i = 0; i < n; i++) {
    dst[i] = pf(src[i]);
  }
}
int main(int argc, char *argv[])
{
    double src[5]={1,2,3,4,5};
    double dst[5];
    transform(src,dst,5,double_sqrt);
    for (int i = 0; i < 5; i++) {
        printf("%f ",dst[i]);
    }
    puts("");

    transform(src,dst,5,double_cbrt);
    for (int i = 0; i < 5; i++) {
        printf("%f ",dst[i]);
    }
    puts("");
    transform(src,dst,5,sqrt);
    for (int i = 0; i < 5; i++) {
        printf("%f ",dst[i]);
    }
    puts("");
    transform(src,dst,5,cbrt);
    for (int i = 0; i < 5; i++) {
        printf("%f ",dst[i]);
    }
    puts("");
    return 0;
}