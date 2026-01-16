#include <stdio.h>
#include <string.h>
char * s_gets(char *s,int n){
    char *ret_val;
    int i=0;
    ret_val=fgets(s,n,stdin);
    if(ret_val)
    {
        char *find=strchr(s,'\n');
        if(find)
            *find='\0';
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