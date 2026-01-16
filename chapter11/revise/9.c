#include <stdio.h>
char * s_gets(char *s,int n){
    char *ret_val;
    int i=0;
    ret_val=fgets(s,n,stdin);
    if(ret_val)
    {
        while(*s!='\n' && *s!='\0')
            s++;
        if(*s=='\n')
            *s='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
int main(void)
{
    char str[5];
    s_gets(str,5);
    printf("%s",str);
    return 0;
}