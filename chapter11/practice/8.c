#include <stdio.h>
#include <string.h>
char * string_in(const char source[],char in[])
{
    const char * p1=source;
    char * p2=in;
    for(;*p1;p1++){
        int has=1;
        for(int i=0;*(p2+i);i++){
            if(*(p1+i)!=*(p2+i)){
                has=0;
                break;
            }
        }
        if (has){
            return (char *)p1;
        }
    }
    return NULL;
}
char* s_gets(char *s, int n) {
    char *ret_val;
    int i = 0;
    ret_val = fgets(s, n, stdin);
    if (ret_val) {
        char *find = strchr(s, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
int main(void)
{
    while(1){
        const int SIZE=10;
        char in[SIZE];
        char source[SIZE];
        printf("请输入一个字符串:");
        s_gets(source,SIZE);
        printf("请输入一个子字符串:");
        s_gets(in,SIZE);
        char * p=string_in(source,in);
        if(p){
            printf("找到子字符串及后续:%s\n",p);
        }
        else{
            printf("未找到子字符串\n");
        }
    }
    return 0;
}