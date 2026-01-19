#include <stdio.h>
#include <stdlib.h>
int seed;
void init_rand_arr(int arr[],int n){
    srand(seed);
    for(int i=0;i<n;i++)
        arr[i]=rand()%10;
}
void statistic_arr(int arr[],int n){
    int count[10]={0};
    for(int i=0;i<n;i++)
        count[arr[i]]++;
    printf("The seed is %d.\n",seed);
    for(int i=0;i<10;i++)
        printf("%3d ",i);
    printf("\n");
    for(int i=0;i<10;i++)
        printf("%3d ",count[i]);
    printf("\n");
}

int main(void)
{
    extern int seed;
    int SIZE=1000;
    int arr[SIZE];
    for(int i=0;i<10;i++)
    {
        seed=i;
        init_rand_arr(arr,SIZE);
        statistic_arr(arr,SIZE);
    }
    return 0;
}