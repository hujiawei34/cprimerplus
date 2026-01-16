#include <stdio.h>
char * str_sch(char *str, char ch){
    int i=0;
    while(str[i]){
        if(str[i]==ch){
            return &str[i];
        }
        i++;
    }
    return NULL;
}
int main(void)
{
    while(1){
        char str[100];
        char ch;
        printf("请输入一个字符串:");
        fgets(str,100,stdin);
        printf("请输入一个字符:");
        ch=getchar();
        while(getchar()!='\n'){
            continue;
        }
        char *pos=str_sch(str,ch);
        if(pos){
            printf("字符%c在字符串%s中的位置是%ld\n",ch,str,pos-str+1);
        }else{
            printf("字符%c不在字符串%s中\n",ch,str);
        }
    }
    return 0;
}