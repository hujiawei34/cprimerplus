/**
 * @file list.c
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief 支持链表操作的函数实现
 * @version 0.1
 * @date 2026-01-28
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/**
 * @brief 局部函数原型
 *
 * @param item
 * @param pnode
 */
static void CopyToNode(Item item, Node *pnode);

/**
 * @brief 初始化一个空链表
 *
 * @param plist
 */
void InitializeList(List *plist)
{
    *plist = NULL;
}

/**
 * @brief is list is null
 *
 * @param plist point to a List
 * @return true pointed List is null
 * @return false pointed List is not null
 */
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief try to malloc a new Node mem,if success retrun true
 *
 * @param plist
 * @return true
 * @return false
 */
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    pt = malloc(sizeof(Node));
    if (pt == NULL)
    {
        full = true;
    }
    else
    {
        full = false;
    }
    free(pt);
    return full;
}

/**
 * @brief
 *
 * @param plist
 * @return unsigned int
 */
unsigned int ListItemCount(const List *plist){
    unsigned int count=0;
    Node * pnode=*plist;
    while(pnode !=NULL)
    {
        ++count;
        pnode=pnode->next;
    }
    return count;
}

/**
 * @brief add item to end of the plist
 *
 * @param item
 * @param plist should initialized
 * @return true if add success else
 * @return false
 */
bool AddItem(Item item, List *plist){
    Node * pnew;
    Node *scan =*plist;
    pnew=malloc(sizeof(Node));
    if(pnew==NULL)
    {
        return false;
    }
    CopyToNode(item,pnew);
    pnew->next=NULL;
    if(scan==NULL)
    {
        //空链表,把pnew 放在开头
        *plist=pnew;
    }else{
        while(scan->next!=NULL)//找到链表的结尾
        {
            scan=scan->next;
        }
        scan->next=pnew;//把pnew添加到链表的结尾
    }
    return true;
}

/**
 * @brief exec pfun to each item of plist
 *
 * @param plist an initialized List pointer
 * @param pfun func pointer,required an Item arg without return
 */
void Traverse(const List *plist, void (*pfun)(Item item)){
    Node * pnode=*plist;
    while(pnode !=NULL)
    {
        (*pfun)(pnode->item);
        pnode=pnode->next;
    }
}

/**
 * @brief free plist memory if has
 *
 * @param plist
 */
void EmptyTheList(List *plist){
    Node * psave;
    while(*plist!=NULL)
    {
        psave=(*plist)->next;
        free(*plist);
        *plist=psave;
    }
}
/**
 * @brief copy item  to pnode item
 * 
 * @param item copy from
 * @param pnode copy to 
 */
static void CopyToNode(Item item,Node *pnode)
{
    pnode->item=item;
}