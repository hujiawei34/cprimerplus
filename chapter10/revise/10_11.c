#include <stdio.h>
int main(void)
{
    float rootbeer[10], things[10][5], *pf, value = 2.2;
    int i = 3;
    // a.
    rootbeer[2] = value;
    // b.
    scanf("%f", &rootbeer); // ok but with compile warning ,this set rootbear[0] from input
    printf("*rootbear=%g\n", *rootbeer);
    printf("rootbear list:");
    for (int i = 0; i < 10; i++)
        printf("%g ", rootbeer[i]);
    putchar('\n');
    //*rootbear=11.1
    // rootbear list:11.1 0 2.2 0 0 0 0 0 0 0

    //c. not ok,rootbear is 常量，无法赋值
    // rootbeer=value;

    //d.ok,print 0.00000
    printf("%f",rootbeer);

    //e.ok =0
    things[4][4]=rootbeer[3];

    //f.not ok,
    // things[5]=rootbeer;
    
    //g.not ok,*pf =value
    // pf=value;

    //h
    pf=rootbeer;

    //11.
    int a[800][600];
    
    return 0;
}