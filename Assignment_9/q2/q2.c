#include <stdio.h>
#include <stdlib.h>

int count(char *string, char goal);
char get_char(char *prompt);
char *get_string(char *prompt);

int main(void)
{
    char *text = get_string("Please input a string: ");
    char val = get_char("Please input a character to count: ");

    printf("The character '%c' appears %d times in text.\n", val, count(text, val));
}

int count(char *string, char goal)
{
    int count = 0;

    for (int i = 0; string[i] != '\n'; i++)
    {
        if (string[i] == goal)
        {
            count++;
        }
    }

    return count;
}

// Gets input from user and returns it
char get_char(char *prompt)
{
    char c;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%c", &c) == 1)
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
    return c;
}

char *get_string(char *prompt)
{
    char *input = malloc(256);
    printf("%s", prompt);
    fgets(input, 256, stdin);
    return input;
}