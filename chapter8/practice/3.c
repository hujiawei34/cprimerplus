#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int lct = 0; // lowercase count
    int uct = 0; // uppercase count
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            lct++;
        else if (isupper(ch))
            uct++;
    }
    printf("lowercase letter num:%d\n", lct);
    printf("uppercase letter num:%d\n", uct);

    return 0;
}