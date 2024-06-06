#include <stdio.h>
#include <string.h>
void swap(char *x, char *b)
{
    char temp;
    temp = *x;
    *x = *b;
    *b = temp;
}

int main(int argc, char *argv[])
{

    // permutations
    // for n in string
    // p1 &c0, p2 &c1
    // move p2 through to the end and print, then move p1 right, set p2 to index 0 again

    char *p1 = argv[1];

    char *p2 = argv[1];

    printf("%c %c", *p1, *p2);

    int n = strlen(argv[1]);
    permutate(p1, 0, n - 1);

    // printf("%d", argc);

    return 0;
}

void permutate(char *a, int l, int r)
{
    int i;
    if (l == r)
    {
        printf("%s\n", a);
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permutate(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}