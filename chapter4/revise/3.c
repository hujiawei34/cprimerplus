#include <stdio.h>
#include <string.h>
int main(void)
{

    //c.
    #define Q "\"HIS Hamlet was a funny without being vulgar.\""
    printf("%s\nhas %ld characters.\n", Q, strlen(Q));
    //HIS Hamlet was a funny without being vulgar.
    //has 44 characters.
    return 0;
}