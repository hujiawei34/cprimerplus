#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
struct name{
    char first[20];
    char last[20];
};
struct bem{
    int limbs;
    struct name title;
    char type[30];

};
void print_bem(struct bem *pb){
    printf("%s %s is a %d-limbed %s.\n",pb->title.first,pb->title.last,pb->limbs,pb->type);
}

int main(int argc, char *argv[])
{
    struct bem *pb;
    struct bem deb={6,{"Berbnazel","Gwolkapwolk"},"Arcturan"};
    pb=&deb;
    //a.
    printf("%d\n",deb.limbs);//6
    printf("%s\n",pb->type);//Arcturan
    printf("%s\n",pb->type+2);//cturan

    //b.
    printf("#1:%s, #2:%s\n",pb->title.last,(*pb).title.last);//Gwolkapwolk,Gwolkapwolk
    //c.
    print_bem(pb);
    return 0;
}