#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int get_int(char *prompt);
void fibo(int n);

int main(void)
{
    int num;

    // Gets input from user until the input is greater than 0
    do
    {
        num = get_int("Please input a positive integer: ");
    }
    while (num < 1);

    if (num != 1)
    {
        printf("First %i terms: ", num);
    }
    else
    {
        printf("First %i term: ", num);
    }

    fibo(num);
}

// Fibonacci sequence
void fibo(int n) {
    int first = 0;
    int second = 1;
    int next_term;

    printf("%i", first);
    if (n > 1)
    {
        printf(", %i", second);
    }

    for (int i = 3; i <= n; ++i) {
        next_term = first + second;
        printf(", %i", next_term);
        first = second;
        second = next_term;
    }
    printf("\n");
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