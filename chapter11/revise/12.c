#include <stdio.h>
#include <string.h>
char *get_blank(char *s) {
  char *find = strchr(s, ' ');
  if (find)
    return find;
  else
    return NULL;
}
int main(void) { 
    char str[5]="abc";
    char *blank=get_blank(str);
    if(blank)
        printf("%s",blank);
    else
        printf("no blank");
    return 0; }