#include <stdio.h>
#include <math.h>

int get_int(char text[]);

int main(void)
{
    int num;
    do 
    {
        num = get_int("Please enter how many primes you want to see: ");
    }
    while (num < 1);

    int printed_primes = 0;
    int current_number = 2;

    printf("First %i prime numbers:", num);

    while (printed_primes < num)
    {
        int isprime = 1;
        int root = sqrt(current_number);
        for (int n = 2; n <= root; n++)
        {
            if (current_number % n == 0)
            {
                isprime = 0;
                break;
            }
        }
        if (isprime)
        {
            if (current_number == 2)
            {
                printf(" %i", current_number);
            }
            else
            {
                printf(", %i", current_number);
            }
            printed_primes++;
        }
        current_number++;
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