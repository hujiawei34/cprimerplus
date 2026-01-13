#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int wn;     // word nums
    int cn = 0; // all word characters nums
    char prev;
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            cn++;
        }
        else
        {
            if (isalpha(prev))
            {
                wn++;
            }
            prev = ch;
            continue;
        }

        prev = ch;
    }
    printf("word num:%d,character num:%d",wn,cn);
    printf("the average word characters num is %.2f", (float)cn / wn);

    return 0;
}