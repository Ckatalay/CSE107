#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    int sum = 0;
    int end = get_int("Please input a positive integer: ");

    while (end < 1)
    {
        end = get_int("Invalid input. Please input a positive integer: ");
    }

    for (int i = 1; i <= end; i += 2)
    {
        sum += i;
    }
    printf("The sum of odd numbers from 1 to %i is %i.\n", end, sum);
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