#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to hold the card requirements
typedef struct
{
    char letter;
    int digit;
} Requirement;

// Function to check if a card meets the requirement
int check_requirement(Requirement *reqs, int num_reqs, char letter, int digit)
{
    for (int i = 0; i < num_reqs; i++)
    {
        if (reqs[i].letter == letter)
        {
            return reqs[i].digit == digit;
        }
    }
    return 1; // If there is no specific requirement, consider it as OK
}

// Function to randomly generate a card
void generate_card(char *letter, int *digit)
{
    *letter = 'A' + rand() % 26; // Random letter from A to Z
    *digit = rand() % 10;        // Random digit from 0 to 9
}

// Function to print the card requirements
void print_requirements(Requirement *reqs, int num_reqs)
{
    printf("Requirements:\n");
    for (int i = 0; i < num_reqs; i++)
    {
        printf("%c-%d\n", reqs[i].letter, reqs[i].digit);
    }
    printf("----\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 11)
    {
        printf("Usage: %s <requirement1> ... <requirement10>\n", argv[0]);
        return 1;
    }

    // Parse command line arguments into requirements
    int num_reqs = argc - 1;
    Requirement *reqs = malloc(num_reqs * sizeof(Requirement));
    for (int i = 0; i < num_reqs; i++)
    {
        if (sscanf(argv[i + 1], "%c-%d", &reqs[i].letter, &reqs[i].digit) != 2)
        {
            printf("Invalid requirement format: %s\n", argv[i + 1]);
            free(reqs);
            return 1;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Print requirements
    print_requirements(reqs, num_reqs);

    // Generate and check 10 random cards
    for (int i = 0; i < 10; i++)
    {
        char letter;
        int digit;
        generate_card(&letter, &digit);
        printf("Generating: %c-%d -- %s\n", letter, digit, check_requirement(reqs, num_reqs, letter, digit) ? "OK" : "not OK");
    }

    printf("----\n");

    // Ask user for a card and check it
    char user_input[10];
    printf("Please input a card: ");
    fgets(user_input, sizeof(user_input), stdin);
    char user_letter;
    int user_digit;
    if (sscanf(user_input, "%c-%d", &user_letter, &user_digit) == 2)
    {
        printf("Card <%c-%d> -- %s\n", user_letter, user_digit, check_requirement(reqs, num_reqs, user_letter, user_digit) ? "OK" : "not OK");
    }
    else
    {
        printf("Invalid card format\n");
    }

    // Free allocated memory
    free(reqs);
    return 0;
}
