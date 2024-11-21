#include <stdio.h>
#include <stdlib.h>

int is_same(int *array1, int *array2, int size);
void sort(int *array, int size);
int *get_array(char *prompt, int size);

int main(void)
{
    int *A = get_array("Enter 5 elements for array A:\n", 5);
    int *B = get_array("Enter 5 elements for array B:\n", 5);

    if (is_same(A, B, 5))
    {
        printf("B is equal to A.\n");
        return 0;
    }

    sort(A, 5);
    sort(B, 5);

    if (is_same(A, B, 5))
    {
        printf("Yes, array B can be made equal to array A.\n");
    }
    else
    {
        printf("No, array B cannot be made equal to array A.\n");
    }

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

void sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
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
        int sign = 0;

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
                    if (!sign)
                    {
                        array[j] = num * -1;
                        sign = 0;
                    }
                    else
                    {
                        array[j] = num;
                    }
                    num = 0;
                    j++;
                }
                else
                {
                    valid_input = 0;
                    break;
                }
            }
            else if (temp == '-')
            {
                sign = 1;
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