/**
 * @file tree.h
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief 二叉查找树
 * 树中不允许有重复的项
 * @version 0.1
 * @date 2026-01-28
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef _TREE_H_
#define _TREE_H_

#include <stdbool.h>

#define SLEN 20

/**
 * @brief 项目结构体
 *
 * 存储宠物的基本信息
 */
typedef struct item
{
    char petname[SLEN]; // 宠物名字
    char petkind[SLEN]; // 宠物种类
} Item;

#define MAXITEMS 10

/**
 * @brief 树节点结构体
 *
 * 二叉查找树的节点，包含数据和左右子节点指针
 */
typedef struct trnode
{
    Item item;             // 节点存储的数据项
    struct trnode *left;   // 指向左子节点的指针
    struct trnode *right;  // 指向右子节点的指针
} Trnode;

/**
 * @brief 树结构体
 *
 * 表示整个二叉查找树，包含根节点和节点数量
 */
typedef struct tree
{
    Trnode *root; // 指向根节点的指针
    int size;     // 树中当前的节点数量
} Tree;

// ==================== 公共接口函数 ====================

/**
 * @brief 初始化树
 */
void InitializeTree(Tree *pt);

/**
 * @brief 检查树是否为空
 */
bool TreeIsEmpty(const Tree *pt);

/**
 * @brief 检查树是否已满
 */
bool TreeIsFull(const Tree *pt);

/**
 * @brief 返回树中的项目数量
 */
int TreeItemCount(const Tree *pt);

/**
 * @brief 向树中添加项目
 */
bool AddItem(const Item *pi, Tree *pt);

/**
 * @brief 从树中删除项目
 */
bool DeleteItem(const Item *pi, Tree *pt);

/**
 * @brief 检查项目是否在树中
 */
bool InTree(const Item *pi, const Tree *pt);

/**
 * @brief 遍历树并对每个项目执行指定函数
 */
void Traverse(const Tree *pt, void (*pfun)(Item item));

/**
 * @brief 删除树中的所有节点
 */
void DeleteAll(Tree *pt);

#endif