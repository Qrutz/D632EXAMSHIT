#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
void pack(uint8_t engine_on, uint8_t floor_pos, uint8_t door_pos, uint8_t brake1, uint8_t brake2)
{
    // check if in range
    if (engine_on > 1 || floor_pos > 7 || door_pos > 3 || brake1 > 1 || brake2 > 1)
    {
        printf("not in range");
        return;
    }

    uint8_t out = (engine_on << 7) | (floor_pos << 4) | (door_pos << 2) | (brake1 << 1) | brake2;

    printf("%0X", out);
}

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        printf("5 entries required");
        return 0;
    }

    uint8_t e = atoi(argv[1]);
    uint8_t f = atoi(argv[2]);
    uint8_t d = atoi(argv[3]);
    uint8_t b1 = atoi(argv[4]);
    uint8_t b2 = atoi(argv[5]);

    pack(e, f, d, b1, b2);

    return 0;
}