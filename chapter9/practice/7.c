#include <stdio.h>
#include <ctype.h>
int get_character_index(char c)
{
    int re=-1;
    if(isalpha(c))
    {
        if(isupper(c))
            re=c-'A'+1;
        else
            re=c-'a'+1;
    }

    return re;
}
int main(void)
{
    char c;
    while((c=getchar())!=EOF)
    {
        printf("%c ",c);
        if(get_character_index(c)==-1)
            printf("is not alpha.\n");
        else
            printf(" index is %d\n",get_character_index(c));

    }

    return 0;
}