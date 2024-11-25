#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int is_same(int *array1, int *array2, int size);
void rotate(int *array, int size);
int *get_array(char *prompt, int size);

int main(void)
{
    int *A = get_array("Enter 5 elements for array A:\n", SIZE);
    int *B = get_array("Enter 5 elements for array B:\n", SIZE);

    if (is_same(A, B, SIZE))
    {
        printf("Yes.\n");
        return 0;
    }

    for (int i = 0; i < SIZE; i++)
    {
        rotate(B, SIZE);

        if (is_same(A, B, 5))
        {
            printf("Yes.\n");

            free(A);
            free(B);

            return 0;
        }
    }

    printf("No.\n");

    free(A);
    free(B);
}

int is_same(int *array1, int *array2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array1[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

void rotate(int *array, int size)
{
    int first = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = first;
}


int *get_array(char *prompt, int size) {
    int *array = malloc(size * sizeof(int));

    while (1)
    {
        printf("%s", prompt);
        char buffer[256];

        fgets(buffer, 256, stdin);
        int num = 0;
        int j = 0;
        int valid_input = 1;

        for (int i = 0; buffer[i] != '\n'; i++)
        {
            int temp = buffer[i];
            if (temp <= '9' && temp >= '0')
            {
                num = num * 10 + (temp - '0');
            }
            else if (temp == ' ')
            {
                if (j < size)
                {
                    array[j] = num;
                    num = 0;
                    j++;
                }
                else
                {
                    valid_input = 0;
                    break;
                }
            }
            else
            {
                valid_input = 0;
                break;
            }
        }
        if (valid_input && j == size - 1)
        {
            array[j] = num;
            break;
        }
        else
        {
            printf("Invalid input. Please enter exactly %d integers separated by spaces.\n", size);
        }
    }
    return array;
}