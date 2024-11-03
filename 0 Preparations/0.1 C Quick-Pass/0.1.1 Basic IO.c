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