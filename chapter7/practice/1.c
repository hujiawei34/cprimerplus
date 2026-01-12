#include <stdio.h>
int main(void)
{
    int b_ct; // blank count
    int n_ct; //\n count
    int o_ct; // other count
    char ch;

    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case ' ':
            b_ct++;
            break;
        case '\n':
            n_ct++;
            break;
        default:
            o_ct++;
        }
    }
    printf("blank count=%d,\\n count=%d,other count=%d\n.", b_ct, n_ct, o_ct);

    return 0;
}