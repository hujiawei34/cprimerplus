/**
 * @file queue.h
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief 队列接口
 * @version 0.1
 * @date 2026-01-28
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef _QUEUE_H_

#define _QUEUE_H_

#include <stdbool.h>

/// @brief 用于use_q.c
// typedef int Item;

/// @brief use in mall.c
typedef struct item
{
    long arrive;
    int processtime;
} Item;

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
    /// @brief 队列 中的项数
    int items;
} Queue;
/**
 * @brief 初始化空队列
 *
 * @param pq
 */
void InitializeQueue(Queue *pq);

/**
 * @brief
 *
 * @param pq
 * @return true
 * @return false
 */
bool QueueIsFull(const Queue *pq);

/**
 * @brief
 *
 * @param pq
 * @return true
 * @return false
 */
bool QueueIsEmpty(const Queue *pq);

/**
 * @brief
 *
 * @param pq
 * @return int
 */
int QueueItemCount(const Queue *pq);

/**
 * @brief 入队,加入item到队列尾端
 *
 * @param item 待入队元素
 * @param pq
 * @return true 入队操作成功
 * @return false
 */
bool EnQueue(Item item, Queue *pq);

/**
 * @brief 出队,从队列首端移除item
 *
 * @param item 移除的item会复制到这个指针上
 * @param pq
 * @return true 出队成功
 * @return false
 */
bool DeQueue(Item *item, Queue *pq);

/**
 * @brief free pq mem
 *
 * @param pq
 */
void EmptyQueue(Queue *pq);

#endif