/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  
    char inp1[100];
    char inp2[100];
    
    
    printf("Input string 1: \n");
    scanf("%s", inp1);
    
        
    printf("Input string 2: \n");
    scanf("%s", inp2);
    
   // Calculate the length of the new concatenated string
    size_t length1 = strlen(inp1);
    size_t length2 = strlen(inp2);
    
    // Allocate memory for the concatenated string (+1 for the null terminator)
    char *newWord = malloc(length1 + length2 + 1);
    
    
     // Manual concatenation using a loop
    for (size_t i = 0; i < length1; i++) {
        newWord[i] = inp1[i];
    }
    
    for (size_t j = 0; j < length2; j++) {
        newWord[length1 + j] = inp2[j];
    }
    
    
    
       printf("Concatenated string: %s\n", newWord);
       
       
        free(newWord);

    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define COURSESL 6
#define MAX_MARKS 100

int main()
{
    int input1[COURSESL];
    
    // Loop to get input for all courses
    for (int i = 0; i < COURSESL; i++) {
        // Ask for input 
        printf("Enter a number for course %d: ", i + 1);
        scanf("%d", &input1[i]);
    }
    
    // Initialize sum to 0
    int sum = 0;

    // Calculate the sum
    for (int i = 0; i < COURSESL; i++) {
        sum += input1[i]; // Add each element to sum
    }
    
    // Calculate percentage
    float percentage = (sum / (float)(COURSESL * MAX_MARKS)) * 100;
    
    // Print the sum and percentage
    printf("The sum of the marks is: %d\n", sum);
    printf("The percentage is: %.2f%%\n", percentage);
    
    // Determine grade based on percentage using if-else
    if (percentage >= 90) {
        printf("Grade A\n");
    } else if (percentage >= 80) {
        printf("Grade B\n");
    } else if (percentage >= 70) {
        printf("Grade C\n");
    } else if (percentage >= 60) {
        printf("Grade D\n");
    } else if (percentage >= 40) {
        printf("Grade E\n");
    } else {
        printf("Grade F\n");
    }
    
    return 0;
}
