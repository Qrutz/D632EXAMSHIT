#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

void unpack(uint8_t packed, int bunnyPos, int JackPos)
{
    uint8_t whoMoves = (packed >> 7) & 0x01;
    uint8_t direction = (packed >> 6) & 0x01;
    uint8_t speedM = (packed >> 4) & 0x02;
    uint8_t steps = (packed >> 1) & 0x0F;

    if (whoMoves == 0)
    {
        // check steps

        if (direction == 0)
        {
            JackPos = JackPos - (steps * speedM);
        }
        else
        {
            JackPos = JackPos + (steps * speedM);
        }
    }
    else
    {
        if (direction == 0)
        {
            bunnyPos = bunnyPos - (steps * speedM);
        }
        else
        {
            bunnyPos = bunnyPos + (steps * speedM);
        }
    }

    char mover[20];
    char directionS[20];

    strcpy(mover, whoMoves == 0 ? "Bunny" : "Jack");
    strcpy(directionS, direction == 0 ? "backward" : "forward");

    printf("%s Moves %d %s, bunny's position: %d, jack's position: %d \n", mover, steps, directionS, bunnyPos, JackPos);
}

int main()
{
    printf("Welcome to the game!\n");
    srand(time(NULL));
    int currentTurn = 0;
    int bunnyPos = 0;
    int jackPos = 0;

    while (currentTurn < 10)
    {

        uint8_t random_byte = rand() % 256; // 256 is 2^8, the number of possible values in a byte
        printf("Bunny draws 1 byte: 0x%02X\n", random_byte);
        unpack(random_byte, bunnyPos, jackPos);
        sleep(1);
        random_byte = rand() % 256; // Generate a new random byte for Jack
        printf("Jack draws 1 byte: 0x%02X\n", random_byte);
        unpack(random_byte, bunnyPos, jackPos);

        sleep(1);
        ++currentTurn;
    }

    if (bunnyPos > jackPos)
    {
        printf("bunny wins");
    }
    {
        printf("jack wins")
    }

    return 0;
}