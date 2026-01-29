/** 简单链表类型的头文件 */
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/* 特定程序的声明 */

#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef Node *List;

/**
 * @brief 初始化一个空链表
 *
 * @param plist 指向一个链表
 */
void InitializeList(List *plist);

/**
 * @brief is list is null
 *
 * @param plist point to a List
 * @return true pointed List is null
 * @return false pointed List is not null
 */
bool ListIsEmpty(const List *plist);

/**
 * @brief
 *
 * @param plist
 * @return true
 * @return false
 */
bool ListIsFull(const List *plist);

/**
 * @brief
 *
 * @param plist
 * @return unsigned int
 */
unsigned int ListItemCount(const List *plist);

/**
 * @brief add item to end of the plist
 *
 * @param item
 * @param plist should initialized
 * @return true if add success else
 * @return false
 */
bool AddItem(Item item, List *plist);

/**
 * @brief exec pfun to each item of plist
 *
 * @param plist an initialized List pointer
 * @param pfun func pointer,required an Item arg without return
 */
void Traverse(const List *plist, void (*pfun)(Item item));

/**
 * @brief free plist memory if has
 *
 * @param plist
 */
void EmptyTheList(List *plist);

#endif