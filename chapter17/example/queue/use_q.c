/**
 * @file use_q.c
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief 驱动程序 ,测试Queue接口
 * 与 queue.c一起编译
 * @version 0.1
 * @date 2026-01-28
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue line;
    Item temp;
    char ch;

    InitializeQueue(&line);
    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value,and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd')
            continue;
        if (ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!QueueIsFull(&line))
            {
                printf("Putting %d into queue\n", temp);
                EnQueue(temp, &line);
            }
            else
            {
                puts("Queue is full!");
            }
        }
        else
        {
            if (QueueIsEmpty(&line))
            {
                puts("Nothing to delete!");
            }
            else
            {
                DeQueue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", QueueItemCount(&line));
        puts("Type a to add, d to delete, q to quit:");
    }
    EmptyQueue(&line);
    puts("Bye!");
    return 0;
}