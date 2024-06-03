#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX 20

int userInputFloor = 0;
int floorState = 0;
int isMoving = 0;

pthread_mutex_t state_mutex;
pthread_cond_t state_cond;

void *inputFunction(void *arg);
void *elevatorFunction(void *arg);

int main(int argc, char *argv[])
{
    pthread_t inputthread, elevatorthread;

    pthread_mutex_init(&state_mutex, NULL);
    pthread_cond_init(&state_cond, NULL);

    // create and start inputthread
    pthread_create(&inputthread, NULL, inputFunction, NULL);

    // create and start elevatorthread
    pthread_create(&elevatorthread, NULL, elevatorFunction, NULL);

    // Wait for threads to finish
    pthread_join(inputthread, NULL);
    pthread_join(elevatorthread, NULL);

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&state_mutex);
    pthread_cond_destroy(&state_cond);

    return 0;
}

void *inputFunction(void *arg)
{
    while (1)
    {
        int floorOption;
        printf("Enter floor (0-%d) or -1 to print status: ", MAX);
        scanf("%d", &floorOption);

        if (floorOption == -1)
        {
            pthread_mutex_lock(&state_mutex);
            if (isMoving)
            {
                printf("Elevator status: moving\n");
            }
            else
            {
                printf("Elevator status: waiting_for_user\n");
            }
            pthread_mutex_unlock(&state_mutex);
            continue;
        }

        if (floorOption > MAX || floorOption < 0)
        {
            printf("Error: please enter a valid floor in range 0-%d.\n", MAX);
            continue;
        }

        pthread_mutex_lock(&state_mutex);

        if (isMoving == 1)
        {
            printf("Error: Elevator is currently moving, please wait.\n");
        }
        else
        {
            userInputFloor = floorOption;
            printf("User entered a floor: %d\n", userInputFloor);
            pthread_cond_signal(&state_cond);
        }

        pthread_mutex_unlock(&state_mutex);
    }

    return NULL;
}

void *elevatorFunction(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&state_mutex);

        // Wait for user input
        while (userInputFloor == floorState)
        {
            pthread_cond_wait(&state_cond, &state_mutex);
        }

        isMoving = 1;

        while (floorState != userInputFloor)
        {
            if (floorState < userInputFloor)
            {
                floorState++;
            }
            else
            {
                floorState--;
            }

            // Print current floor
            printf("Elevator at floor: %d\n", floorState);

            // Sleep for 1 second to simulate travel time
            sleep(1);
        }

        isMoving = 0;
        printf("Elevator has arrived at floor: %d\n", floorState);

        pthread_mutex_unlock(&state_mutex);
    }

    return NULL;
}
