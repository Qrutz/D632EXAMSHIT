/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b; // temp = 6; 
        b = a % b; // b = 5, b == 1;
        a = temp;  // a == 6; a == 5
    }
    printf("%d", a);
    return a;
    
}

int addFraction(int a, int c, int b, int d) {
    
    
    
    int numerator = a * d + b * c;
    int demoninator = c *d;
    
    int divisor = gcd(numerator, demoninator);
    
    
     numerator /= divisor;

    demoninator /= divisor;

    printf("The result is: %d/%d\n", numerator, demoninator);
    
    return 1;
    
}

int subTraction(int a, int c, int b, int d) {
    
    
    
    int numerator = a * d - b * c;
    int demoninator = c *d;
    
    int divisor = gcd(numerator, demoninator);
    
    
     numerator /= divisor;

    demoninator /= divisor;

    printf("The result is: %d/%d\n", numerator, demoninator);
    
    return 1;
    
}

int mulFraction(int a, int c, int b, int d) {
      int numerator = a * c;
    int demoninator = b * d;
    
        int divisor = gcd(numerator, demoninator);
    
    numerator /= divisor;
    demoninator /= divisor;
    
    printf("The result is: %d/%d\n", numerator, demoninator);
    
    return 1;
    
    
    
}


int main()
{

    
    addFraction(1, 2, 1, 3);   // Expected output: 5/6
    
    subTraction(1, 2, 1, 3);   // Expected output: 5/6
    
    mulFraction(1, 2, 1, 3);
    
    
    

    return 0;
}
