#include <stdio.h>
int main(void)
{
    int zippo[4][2]={{2,4},{6,8},{1,3},{5,7}};
    int (*pz)[2]; //一个指针，指向int[2]的数组
    int *tz[2];//[]优先级比* 高，所以定义的是一个数组 ，这个数组有两个指向int的指针 int *(tz[2]) 
    pz=zippo;

    printf("    pz=%p,    pz+1=%p\n",pz,pz+1);//pz[0],pz[1]
    printf(" pz[0]=%p, pz[0]+1=%p\n",pz[0],pz[0]+1);//pz[0],pz[1]
    printf("   *pz=%p,   *pz+1=%p\n",*pz,*pz+1);//pz[0],pz[1]
    printf("pz[0][0]=%d\n",pz[0][0]);//2
    printf("  *pz[0]=%d\n",*pz[0]);//2
    printf("    **pz=%d\n",**pz);//pz[0][0]=2
    printf("pz[2][1]=%d\n",pz[2][1]);//3
    printf("*(*(pz+2))+1)=%d\n",*(*(pz+2)+1));//pz[2][1]=3



    return 0;
}