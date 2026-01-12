#include <stdio.h>
int main(void)
{
    char ch;
    int lc = 0; // lower count
    int uc = 0; // upper count
    int oc = 0; // other count

    while ((ch = getchar()) != '#')
    {
        if (ch >= 'a' && ch <= 'z')
            lc++;
        else if (ch >= 'A' && ch <= 'Z')
            uc++;
        oc++;
    }
    printf("%d lowercase, %d uppercase, %d other.\n", lc, uc, oc);

    return 0;
}