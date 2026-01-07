#include <stdio.h>
#include <string.h>
int main(void)
{
    //a.
    printf("He sold the painting for $%2.2f.\n", 2.345e2);
    //He sold the painting for $234.50.

    //b.
    printf("%c%c%c\n",'H',105,'\41');
    //Hi!

    //c.
    #define Q "HIS Hamlet was a funny without being vulgar."
    printf("%s\nhas %ld characters.\n", Q, strlen(Q));
    //HIS Hamlet was a funny without being vulgar.
    //has 44 characters.

    //d.
    printf("Is %2.2e the same as %2.2f?\n",1201.0,1201.0);
    //Is 1.20e+03 the same as 1201.00?
    return 0;
}