#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 1. 定义int[10]数组
    int arr[10];
    
    // 2. 设置随机数种子，确保每次运行生成不同的随机数序列
    // time(NULL) 获取当前时间戳，作为srandom()的种子参数
    srandom((unsigned int)time(NULL));
    
    // 3. 循环遍历数组，使用random()初始化每个元素
    for (int i = 0; i < 10; i++) {
        // 直接赋值random()返回值（非负长整型，转换为int存储）
        arr[i] = (int)random()%1000;
        
        // 可选：如需限定随机数范围（例如0~99），可使用取模运算
        // arr[i] = (int)random() % 100;
    }
    
    // 4. 打印数组，验证初始化结果
    printf("初始化后的int[10]数组：\n");
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}