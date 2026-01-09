#include <stdio.h>
int main(void)
{
    //a.
    printf("====a====");
    int n;
    int status=scanf("%d",&n);
    printf("success to read an integer\n");

    //b.
    int x=4;
    printf("====b====");
    printf("x!=5 result:%d\n",x !=5);

    //c
    printf("====c====");
    int c=20;
    printf("c>=20 result:%d\n",c>=20);

    return 0;
}