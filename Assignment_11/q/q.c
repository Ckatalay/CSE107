#include <stdio.h>
#include <stdlib.h>

int get_int(char *prompt);
float get_float(char *prompt);
char *get_string(char *prompt);

int main(void)
{
    int id = get_int("Student ID: ");
    char *name = get_string("Name: ");
    char *surname = get_string("Surname: ");
    float gpa = -1;
    while (gpa < 0 || gpa > 4)
    {
        gpa = get_float("GPA: ");
        if (gpa < 0 || gpa > 4)
        {
            printf("Invalid GPA, please input a value between 0 and 4.\n");
        }
    }

    printf("Student Information:\n");
    printf("------------------------------------------------------\n");
    printf("%-15s %-12s %-14s %s\n", "Student ID", "Name", "Surname", "GPA");
    printf("------------------------------------------------------\n");
    printf("%-15d %-12s %-14s %.2f\n", id, name, surname, gpa);

    free(name);
    free(surname);
}

// Gets input from user and returns it
int get_int(char *prompt)
{
    int i;
    char c;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &i) == 1)
        {
            // Valid integer input
            while ((c = getchar()) != '\n' && c != EOF);
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

// Gets input from user and returns it
float get_float(char *prompt)
{
    char c;
    float f;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%f", &f) == 1)
        {
            // Valid integer input
            while ((c = getchar()) != '\n' && c != EOF);
            return f;
        }
        else
        {
            // Invalid input, clear the buffer
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

char *get_string(char *prompt)
{
    char *buffer = malloc(50 * sizeof(char));
    printf("%s", prompt);
    fgets(buffer, 50, stdin);

    for (int i = 0; i < 50; i++)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
        }
    }
    return buffer;
}