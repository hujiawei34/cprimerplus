#include <stdio.h>
#include <string.h>
#include "my.h"
void remove_blank(char str[])
{
    int len=strlen(str);
    int i=0;
    for(int j=0;j<len;j++){
        if(str[j]!=' '){
            str[i++]=str[j];
        }
    }
    str[i]='\0';
}
int main(void)
{
    char str[100];
    printf("请输入一个字符串:");
    s_gets(str,100);
    while(*str){
        remove_blank(str);
        printf("删除空格后的字符串:%s\n",str);
        printf("请继续输入一个字符串:");
        s_gets(str,100);
    }
    return 0;
}