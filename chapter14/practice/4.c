#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define nlen 10
#define slen 10
struct NAME{
    char fname[slen];
    char mname[slen];
    char lname[slen];
};
struct s1{
    char number[nlen];
    struct NAME name;
};
void show_s(struct s1 *s,int n){
    for(int i=0;i<n;i++)
    {
        printf("%s, %s",s[i].name.lname,s[i].name.fname);
        if(strlen(s[i].name.mname)>0)
            printf(" %s.",s[i].name.mname);
        printf(" -- %s\n",s[i].number);
    }
}
void show_s2(struct s1 s[],int n){
    for(int i=0;i<n;i++)
    {
        printf("%s, %s",s[i].name.lname,s[i].name.fname);
        if(strlen(s[i].name.mname)>0)
            printf(" %c.",s[i].name.mname[0]);
        printf(" -- %s\n",s[i].number);
    }
}
int main(int argc, char *argv[])
{
    struct s1 s[5];
    strcpy(s[0].number,"1234567890");
    strcpy(s[0].name.fname,"John");
    strcpy(s[0].name.mname,"Q");
    strcpy(s[0].name.lname,"Public");

    strcpy(s[1].number,"1234567891");
    strcpy(s[1].name.fname,"Theon");
    strcpy(s[1].name.mname,"Aya");
    strcpy(s[1].name.lname,"Lob");
    // show_s(&s,2);
    show_s2(s,2);
    return 0;
}