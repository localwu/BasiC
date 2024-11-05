#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
动态内存分配-基本数据类型
例如 p 地址为 100，存储内容为 int 地址指针的 500，则 *p 地址为 500，此时对 *p 赋值，则是对地址为 500 的数据进行操作。
*/
void dynamicMemoryAllocation1()
{
    printf("\n-----------001-----------\n");
    int *p;
    p = (int *)malloc(sizeof(int)); // malloc() 返回值需要强制转换成目标数据格式的指针
    *p = 16;                        // *p 在非定义阶段表示操作 p 中存储的地址
    printf("%d", *p);
    free(p); // 主动释放
}

/*
动态内存分配-字符串
*s 只是解引用了 s，也就是获取了 s 指向的那个字符（在这个例子中是 'H'），
而 printf 需要的是整个字符串，也就是从 s 指向的地址开始的一系列字符，直到遇到 '\0'。
总结：printf("%s\n", s); 正确地使用了 s 作为一个指向字符串首字符的指针，
而 *s 只是获取了这个指针指向的第一个字符，并不能用来打印整个字符串。
*/
void dynamicMemoryAllocation2()
{
    printf("\n-----------002-----------\n");
    char *s;
    s = (char *)malloc(sizeof(char) * 10); // malloc() 返回值需要强制转换成目标数据格式的指针
    strcpy(s, "Hello");
    printf("%c\n", *s);
    printf("%s", s);
    free(s); // 主动释放
}

/*
动态内存分配-数组
使用了 arr 作为一个指向数组首元素的指针，访问方式直接使用 arr，而不是 *arr。
*/
void dynamicMemoryAllocation3()
{
    printf("\n-----------003-----------\n");
    int *arr = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d,", arr[i]);
    }
    free(arr); // 主动释放
}

/*
动态内存分配-结构体
结构体仍然可以看成一个数组，只是每个元素不是单独存储，而是存储在连续的内存中。
访问方式直接使用 p，而不是 *p。
struct p *p;与point *p是等价的，只是写法不同。
为什么 float 占用 4 字节，char 占用 1 字节，两个 float，一个 char 到了 point 中要占用 12 字节呢？
因为字节对齐，所以在 point 中 float 占用 4 字节，char 占用 4 字节。
关于字节对齐：《深入理解C指针》
*/
typedef struct p
{
    float x;
    float y;
    char c;
} point;
void dynamicMemoryAllocation4()
{
    printf("\n-----------004-----------\n");
    point *p;
    p = (point *)malloc(sizeof(point));
    p->x = 1.0;
    p->y = 2.0;
    printf("%zu\n", sizeof(char) + sizeof(float) + sizeof(float));
    printf("%zu\n", sizeof(point));
    printf("(%f,%f)", p->x, p->y);
    free(p); // 主动释放
}

int main(int argc, char const *argv[])
{
    printf("\n----------START----------\n");
    dynamicMemoryAllocation1();
    dynamicMemoryAllocation2();
    dynamicMemoryAllocation3();
    dynamicMemoryAllocation4();
    printf("\n-----------END-----------\n");
    return 0;
}