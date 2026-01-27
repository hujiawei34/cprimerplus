#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
  
struct s1{
    double r;
    double a;
};
struct s2{
    double x;
    double y;
};
struct s2 func(struct s1 s)
{
    struct s2 re;
    re.x=s.r*cos(s.a);
    re.y=s.r*sin(s.a);
    return re;

}
int main(int argc, char *argv[])
{
    struct s1 s={1,0.5};
    struct s2 re=func(s);

    printf("(%g %g) -> (%g %g)\n",s.r,s.a,re.x,re.y);

    return 0;
}
