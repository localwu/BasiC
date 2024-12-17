#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define StdSize 10
typedef int ElemType;

// 获取当前时间
struct tm *getCurrentTime()
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);                 // 获取当前时间
    timeinfo = localtime(&rawtime); // 将时间转换为本地时间
    return timeinfo;
}

// 格式化时间
char *formatTime(struct tm *timeinfo)
{
    // 分配一块足够大的内存来存储格式化后的时间字符串（包括空字符）
    char *buffer = (char *)malloc(20 * sizeof(char));
    if (buffer == NULL)
    {
        // 内存分配失败，返回NULL
        return NULL;
    }
    // 使用strftime将时间格式化到buffer中
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
    // 返回buffer的指针
    return buffer;
}

/* 链表基本操作 Link List Basic Operation */

typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

/*
初始化链表
param: Node *L
return: void
*/
Node *InitList(Node *L)
{
    Node *Head = (Node *)malloc(sizeof(Node));
    Head->data = 0;
    Head->next = NULL;
    return Head;
}

/*
销毁链表
param: Node *L
return: void
*/
void DestroyList(Node *L)
{
    free(L->data);
    free(L);
}

/*
输出链表
param: Node *L
return: void
*/
void printList(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

/*
插入元素
param: Node *L, ElemType elem, int pos
return: bool
*/
bool insertElem(Node *L, int pos, ElemType elem)
{
    // Node *p = L;
    // int i = 0;
    // while (p != NULL && i < pos)
    // {
    //     p = p->next;
    //     i++;
    // }
    // if (p == NULL)
    // {
    //     return false;
    // }
    // Node *s = (Node *)malloc(sizeof(Node));
    // s->data = elem;
}

/*
头插法插入元素
param: Node *L, ElemType elem
return: bool
*/
bool headInsertElem(Node *L, ElemType elem)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        return false;
    }
    p->data = elem;
    p->next = L->next;
    L->next = p;
    return true;
}

/*
尾插法
param: Node *L, ElemType e
return: bool
*/
bool appendElem(Node *L, ElemType elem)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = elem;
    s->next = NULL;
    p->next = s;
    return true;
}

int main()
{
    printf("---%s---", formatTime(getCurrentTime()));
    printf("\n----------START----------\n");

    Node *L = InitList(L);
    printList(L);
    int elem;
    headInsertElem(L, 11);
    headInsertElem(L, 12);
    headInsertElem(L, 13);
    for (int i = 0; i < 1; i++)
    {
        // headInsertElem(L, 11 + i);
    }
    // insertElem(L, 9, 100);
    // deleteElem(L, L->length - 1);
    printList(L);
    printf("\n-----------END-----------\n");
}