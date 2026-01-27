#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
// a.
#define FPM 5280
    double miles = 10;
    double dist = FPM * miles;
    printf("dist=%g\n", dist);

// b.
#define FEET 4
#define POD FEET + FEET
    int plort = FEET * POD; // 4*4+4=20
    printf("plort=%d\n", plort);

// c.
//  #define SIX = 6;
//  int nex=SIX;//int nex==
//  printf("%s\n",SIX);

// d.
#define NEW(X) X + 5
    int y = 1;
    y = NEW(y); // y=1+5=6
    int berg = 1;
    int lob = 2;
    int est = 3;
    int nilp = 4;
    berg = NEW(berg) * lob;    // 1+5*2=11
    est = NEW(berg) / NEW(y);  // 11+5/6+5=16
    nilp = lob * NEW(-berg);   // 2*-11+5=-22+5=-17
    printf("y=%d\n", y);       // 6
    printf("berg=%d\n", berg); // 11
    printf("est=%d\n", est);   // 16
    printf("nilp=%d\n", nilp); //-17

// 2
#define NEW(X) ((X) + 5)
    y = 1;
    y = NEW(y); // y=1+5=6
    berg = 1;
    lob = 2;
    est = 3;
    nilp = 4;
    berg = NEW(berg) * lob;    // ((1)+5)*2=12
    est = NEW(berg) / NEW(y);  // ((12)+5)/((6)+5)=17/11=1
    nilp = lob * NEW(-berg);   // 2*((-12)+5)=-14
    printf("y=%d\n", y);       // 6
    printf("berg=%d\n", berg); // 12
    printf("est=%d\n", est);   // 1
    printf("nilp=%d\n", nilp); //-14
    return 0;
}