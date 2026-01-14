#include <stdio.h>
int main(void)
{
    int grid[30][100];
    //a.
    grid[22][56];
    *(*(grid+22)+56);

    //b.
    grid[22][0];
    *grid[22];
    **(grid+22);
    //c.
    grid[0][0];
    *grid[0];
    **grid;
    return 0;
}