#include <stdio.h>
void chline(char ch,int i,int j)
{
    for(int x=0;x<j;x++)
    {
        for(int y=0;y<i;y++)
            putchar(ch);

        putchar('\n');

    }
}
int main(void)
{
    chline('=',3,4);
    chline('-',5,10);

    return 0;
}