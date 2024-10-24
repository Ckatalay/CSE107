#include <stdio.h>

// Function prototypes
int get_int(char *prompt);
int fact(int n);

int main(void)
{
    int num;

    // Gets input from user until the input is greater than 0
    do
    {
        num = get_int("Please input a positive integer: ");
    }
    while (num < 1);

    // Checks n to determine factorial or square
    if (num < 10)
    {
        printf("Factorial of %i is %i\n", num, fact(num));
    }
    else
    {
        printf("Square of %i is %i\n", num, num * num);
    }
}

// Calculates the factorial of n
int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n-1);
    }
}

// Gets input from user and returns it
int get_int(char *prompt)
{
    int i;
    char c;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%i", &i) == 1)
        {
            // Valid integer input
            break;
        }
        else
        {
            // Invalid input, clear the buffer
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    return i;
}