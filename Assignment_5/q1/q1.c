#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    int x = get_int("Input the first integer: ");
    int y = get_int("Input the second integer: ");

    int op = get_int("Operations:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nPlease choose the operation you want: ");
    while (op < 1 || op > 4)
    {
        printf("Invalid option. Please choose a number between 1 and 4.\n");
        op = get_int("Operations:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nPlease choose the operation you want: ");
    }

    switch (op)
    {
    case 1:
        printf("%i + %i = %i\n", x, y, x + y);
        break;

    case 2:
        printf("%i - %i = %i\n", x, y, x - y);
        break;

    case 3:
        printf("%i * %i = %i\n", x, y, x * y);
        break;

    case 4:
        if (y == 0)
        {
            printf("Error: Divison by zero is no allowed.\n");
        }
        else
        {
            printf("%i / %i = %.2f\n", x, y, (float)x / y);
            break;
        }
    
    default:
        break;
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