#include <stdio.h>

#define TEXT "happynewyear"

int count(char *string, char goal);
char get_char(char *prompt);

int main(void)
{
    char val = get_char("Please input a character to count: ");

    printf("The character '%c' appears %d times in text.\n", val, count(TEXT, val));
}

int count(char *string, char goal)
{
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++)
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