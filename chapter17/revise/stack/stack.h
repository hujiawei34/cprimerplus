/**
 * @file stack.h LIFO (last in firt out ) stack adt
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-01-30
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>
#

#define NLEN 10
#define MAX_S 100 //max number of stack
typedef struct item
{
    char name[NLEN];
    char dept[NLEN];
    int age;
} Item;
typedef struct stacknode
{
    struct stacknode *ahead;
    struct item item;
    int count;
} Stacknode;
typedef struct stacknode *stack;


void InitializeStack(stack s);

bool StackIsEmpty(stack s);
bool StackIsFull(stack s);

bool Popup(stack s,Item * pi);

bool Stash(stack s,const Item * pi);

void EmptyStack(stack s);

#endif