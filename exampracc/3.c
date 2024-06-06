
#include <stdio.h>

void swap2(int *x, int *y)
{
    int temp;
    temp = *x;

    *x = *y;
    printf("temp=%d, x=%d, y=%d", temp, x, y);
    *y = temp;
    printf("temp=%d, x=%d, y=%d", temp, x, y);
}

int main()
{
    int a = 2;
    int b = 3;

    swap2(&a, &b);

    printf(", x=%d, y=%d", a, b);

    return 0;
}
