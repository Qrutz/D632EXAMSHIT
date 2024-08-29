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
