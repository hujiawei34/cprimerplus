/**
 * @file stack.c 实现栈操作
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-01-30
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
static void copyItem(Item *des, const Item *src);

void InitializeStack(stack s)
{
    s->ahead = NULL;
    s->count = 0;
}

bool StackIsEmpty(stack s)
{
    return s->count == 0;
}
bool StackIsFull(stack s)
{
    return s->count == MAX_S;
}

bool Popup(stack s, Item *pi)
{
    if (StackIsEmpty(s))
    {
        return false;
    }
    copyItem(pi, &s->item);
    s->count--;
    stack temp = s;
    s = s->ahead;
    free(temp);
    return true;
}

bool Stash(stack s, const Item *pi)
{
    if (StackIsFull(s))
    {
        return false;
    }

    stack new = malloc(sizeof(stack));
    copyItem(&new->item,pi);
    new->count = s->count;
    new->count++;
    new->ahead = s;
    s = new;
    return true;
}

void EmptyStack(stack s)
{
    Item temp;
    while (Popup(s, &temp))
        ;
}
static void copyItem(Item *des, const Item *src){

}