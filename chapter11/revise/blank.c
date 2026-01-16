#include <stdio.h>
#include <ctype.h>

void set_lower(char *s) {
    while (*s) {
        *s = tolower((unsigned char)*s);
        s++;
    }
}

int main(void)
{
    char s[] = "Hello World!";  // 改成数组，内容在可写内存中
    set_lower(s);
    puts(s);
    return 0;
}