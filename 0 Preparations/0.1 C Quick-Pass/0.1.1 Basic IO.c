// 0.1.1 Basic IO.c

#include <stdio.h>

int main()
{
    normalPrintf();
    formatPrintf();
    is32or64();
    normalPrintf();
}

void normalPrintf()
{
    printf("Hello World\n");
}
void formatPrintf()
{
    char c = 127;
    short s = 32767;
    int i = 4294967295;
    long l = 1234567890;
    long long ll = 12345678901234567890;
    float f = 8.340;
    double d = 8.34016017;
    size_t zu = sizeof(long);

    printf("char f=%c\n", c);
    printf("short s=%hd\n", s);
    printf("int i=%d\n", i);
    printf("long l=%ld\n", l);
    printf("long long ll=%lld\n", ll);
    printf("float f=%f\n", f);
    printf("double d=%lf\n", d);
    printf("size_t zu=%zu\n", zu);
}

void is32or64()
{
    size_t zu = sizeof(long);
    if (zu == 4)
        printf("你的电脑可能是32位的\n");
    else if (zu == 8)
        printf("你的电脑可能是64位的\n");
    else
        printf("无法检测该设备为32或64位\n");
}

/*
要点01


*/

/*
要点02

各数据类型字节数
 TYPE  32b  64b
char    1    1
short   2    2
int     4    4
long    4    8
float   4    8
double  8    8
*/

/*
要点03

printf格式控制符，用于指定输出数据的格式：

整数类型：
    %d或%i：用于输出有符号的十进制整数。
    %u：用于输出无符号的十进制整数。
    %o：用于输出无符号的八进制整数。
    %x：用于输出无符号的十六进制整数（小写字母）。
    %X：用于输出无符号的十六进制整数（大写字母）。
    %ld或%li：用于输出长整型的有符号十进制整数（long类型）。
    %lu：用于输出长整型的无符号十进制整数（unsigned long类型）。
    %lld：用于输出长长整型的有符号十进制整数（long long类型）。
    %llu：用于输出长长整型的无符号十进制整数（unsigned long long类型）。
浮点类型：
    %f：以十进制形式输出float类型的小数，默认保留六位小数。
    %lf：以十进制形式输出double类型的小数，默认保留六位小数。
    %e或%E：以指数形式输出浮点数。%e的结果中e小写，%E的结果中E大写。
    %g或%G：根据数值大小自动选择使用%f或%e/%E格式输出，且不会在最后强加0来凑够有效数字的位数或小数部分的位数。
字符和字符串：
    %c：用于输出单个字符。
    %s：用于输出字符串。
指针类型：
    %p：用于输出指针地址（内存地址，以十六进制格式显示）。
其他：
    %%：用于输出百分号%。

printf格式控制符还可以包含标志字符、指定宽度、指定精度等，以进一步定制输出格式。
    例如，%-5d表示左对齐且宽度为5的十进制整数，%.2f表示保留两位小数的十进制浮点数。
*/