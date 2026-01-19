#include <stdio.h>
#include <stdlib.h>
void init_rand_arr(int arr[],int n){
    for(int i=0;i<n;i++)
        arr[i]=rand()%100;
}
void print_arr(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void sort(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}
int main(void)
{
    int SIZE=100;
    int arr[SIZE];
    init_rand_arr(arr,SIZE);
    print_arr(arr,SIZE);
    sort(arr,SIZE);
    print_arr(arr,SIZE);
    return 0;
}