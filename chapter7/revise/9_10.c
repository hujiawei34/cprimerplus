#include <stdio.h>
void origin(void)
{
    /**input
     * q
     * c
     * h
     * b
     */
    char ch;

    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            continue;
        printf("Step 1\n");
        if (ch == 'c')
            continue;
        else if (ch == 'b')
            break;
        else if (ch == 'h')
            goto laststep;
        printf("Step 2\n");
    laststep:
        printf("Step 3\n");
    }
    printf("Done\n");
    /**
     * this will print:
     * q
     * Step 1
     * Step 2
     * Step 3
     * c
     * Step 1
     * h
     * Step 1
     * Step 3
     * b
     * Step 1
     * Done
     */
}
void rewrite(void)
{
    /** rewrite origin without continue and goto */
    char ch;

    while ((ch = getchar()) != '#')
    {
        if (ch != '\n')
        {
            printf("Step 1\n");
            if (ch != 'c')
            {
                if (ch == 'b')
                    break;
                else if (ch != 'h')
                    printf("Step 2\n");
                printf("Step 3\n");
            }
        }
    }
    printf("Done\n");
}

int main(void)
{
    // origin()
    rewrite();
    return 0;
}