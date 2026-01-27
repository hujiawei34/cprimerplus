#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define LEN 20
#define NUMS 100
struct names{
    char fn[LEN];
    char ln[LEN];
};
void initarray(struct names * nlist,int n);
void showarray(const struct names nlist[],int n);
int compare(const void *a,const void *b);
int main(int argc, char *argv[])
{
    struct names nlist[NUMS];
    initarray(nlist,NUMS);
    showarray(nlist,NUMS);
    printf("======after sort=======\n");
    qsort(nlist,NUMS,sizeof(struct names),compare);
    showarray(nlist,NUMS);
    return 0;
}
int compare(const void *a,const void *b)
{
    struct names *n1=(struct names *)a;
    struct names *n2=(struct names *)b;
    int re=strcmp(n1->fn,n2->fn);
    if(re==0)
    {
        return strcmp(n1->ln,n2->ln);
    }
    return re;
}
void initarray(struct names *nlist,int n)
{
    FILE * fp=fopen("6.txt","r");
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%s %s\n",nlist[i].ln,nlist[i].fn);
    }
}
void showarray(const struct names nlist[],int n){
    for(int i=0;i<n;i++)
    {
        printf("%-10s %-10s\n",nlist[i].ln,nlist[i].fn);
    }
}