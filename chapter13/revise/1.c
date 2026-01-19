#include <stdio.h>
int main(void)
{
    // int *fp;
    FILE *fp;
    int k;
    // fp = fopen("gelation");
    fp = fopen("gelation", "w");
    for (k = 0; k < 30; k++)
        // fputs(fp, "Nanette eats gelation.");
        fputs("Nanette eats gelation.",fp);
    fclose(fp);

    return 0;
}