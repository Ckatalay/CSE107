#include <stdio.h>

// Function prototypes
int get_int(char *prompt);
int fibo(int n);

int main(void)
{
    int n;

    // Gets input from user until the input is greater than 0
    do
    {
        n = get_int("Please input a positive integer: ");
    }
    while (n < 1);

    printf("First %i terms: ", n);

    for (int i = 1; i < n; i++)
    {
        printf("%i, ", fibo(i));
    }
    printf("%i\n", fibo(n));
}

int fibo(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibo(n-1) + fibo(n-2);
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