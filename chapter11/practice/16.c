#include <stdio.h>
#include "my.h"
#include <ctype.h>
void print_file_lines(char (*str)[100]){
    int i=0;
    while(str[i][0]!='\0'){
        printf("%s", str[i]);
        i++;
    }
}
void print_file_lines_upper(char (*str)[100]){
    int i=0;
    while(str[i][0]!='\0'){
        for(int j=0;str[i][j]!='\0';j++){
            putchar(toupper(str[i][j]));
        }
        i++;
    }
}
void print_file_lines_lower(char (*str)[100]){
    int i=0;
    while(str[i][0]!='\0'){
        for(int j=0;str[i][j]!='\0';j++){
            putchar(tolower(str[i][j]));
        }
        i++;
    }
}
int main(int argc, char *argv[])
{
    char str[LINES][LENGTH_LIMIT];
    read_file_lines(str);
    char option='p';
    if(argc>1){
        option=argv[1][1];
    }
    switch (option) {
        case 'p':
            print_file_lines(str);
            break;
        case 'u':
            print_file_lines_upper(str);
            break;
        case 'l':
            print_file_lines_lower(str);
            break;
        default:
            printf("Usage: %s -[p|u|l]\n", argv[0]);
            break;
    }
    return 0;
}