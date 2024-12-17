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

/* 线性表基本操作 Sequence List Basic Operation */

typedef struct SqList
{
    ElemType *data;
    int length;  // 顺序表当前长度，相当于指向最后一个元素的下一位
    int MaxSize; // 顺序表最大长度，eg.100,对应下标支持0-99
} SqList;

/*
初始化顺序表
param: SqList *L
return: void
*/
SqList *InitList(int MaxSize)
{
    SqList *L = (SqList *)malloc(sizeof(SqList));
    L->data = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
    L->MaxSize = MaxSize;
    L->length = 0;
    return L;
}

/*
销毁顺序表
param: SqList *L
return: void
*/
void DestroyList(SqList *L)
{
    free(L->data);
    free(L);
}

/*
清空顺序表
param: SqList *L
return: void
*/
void clearList(SqList *L)
{
    L->length = 0;
}

/*
获取顺序表长度
param: SqList *L
return: int
*/
int getLength(SqList *L)
{
    return L->length;
}

/*
获取顺序表第i个元素
param: SqList *L, int i
return: ElemType
*/
ElemType getElem(SqList *L, int index)
{
    if (index < 0 || index > (L->length - 1))
    {
        printf("无法获取，错误位置\n");
        return 0;
    }
    return L->data[index];
}

/*
获取顺序表对应元素的下标
param: SqList *L, ElemType e
return: int
*/
int getIndex(SqList *L, ElemType elem)
{
    for (int index = 0; index <= (L->length - 1); index++)
    {
        if (L->data[index] == elem)
        {
            return index;
        }
    }
    return -1;
}

/*
查找元素
param: SqList *L, ElemType e
return: bool
*/
bool findElem(SqList *L, ElemType elem)
{
    for (int index = 0; index <= (L->length - 1); index++)
    {
        if (L->data[index] == elem)
        {
            return true;
        }
    }
    return false;
}

/*
判断是否为空
param: SqList *L
return: bool
*/
bool isEmpty(SqList *L)
{
    return L->length == 0;
}

/*
尾插法插入元素
param: SqList *L,
return: bool
*/
bool appendElem(SqList *L, ElemType elem)
{
    if (L->length >= L->MaxSize)
    {
        printf("无法添加，表已满\n");
        return false;
    }
    L->data[L->length] = elem;
    L->length++;
    return true;
}

/*
插入元素
param: SqList *L, int i, ElemType e
return: bool
*/
bool insertElem(SqList *L, int index, ElemType e)
{
    if (index < 0 || index > L->length)
    {
        printf("无法插入，错误位置\n");
        return false;
    }
    if (L->length >= L->MaxSize)
    {
        printf("无法插入，表已满\n");
        return false;
    }
    for (int j = L->length; j >= index; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[index] = e;
    L->length++;
    return true;
}

/*
删除元素
param: SqList *L, int i
return: ElemType
*/
ElemType deleteElem(SqList *L, int index)
{
    if (index < 0 || index > (L->length - 1))
    {
        printf("无法删除，错误位置\n");
        return 0;
    }
    ElemType elem = L->data[index - 1];
    for (int j = index; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return elem;
}

/*
打印顺序表
param: SqList *L
return: void
*/
void printList(SqList *L)
{
    for (int index = 0; index <= (L->length - 1); index++)
    {
        printf("%d ", L->data[index]);
    }
}

int main()
{
    printf("---%s---", formatTime(getCurrentTime()));
    printf("\n----------START----------\n");

    SqList *L = InitList(StdSize);
    int elem;
    for (int i = 0; i < 9; i++)
    {
        appendElem(L, 11 + i);
    }
    insertElem(L, 9, 100);
    deleteElem(L, L->length - 1);
    printList(L);
    printf("\n-----------END-----------\n");
}