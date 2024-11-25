#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

float *calc(int arr[SIZE][SIZE][SIZE], int freq, int size, int *mode_count);
int get_int(char *prompt);
void sort(int *array, int size);

int main(void)
{
    int cube[SIZE][SIZE][SIZE] =
    {
        {{5, 5, 12}, {13, 15, 7}, {10, 5, 13}},
        {{18, 10, 15}, {7, 10, 15}, {12, 12, 10}},
        {{12, 7, 15}, {10, 12, 15}, {10, 10, 12}}
    };

    int check = get_int("Enter a weight to check its frequency: ");
    int mode_count;

    float *calcs = calc(cube, check, SIZE, &mode_count);

    printf("1. Mean: %.2f\n2. Median: %.2f\n3. Range: [%.0f, %.0f]\n4. Modes: ", calcs[0], calcs[1], calcs[2], calcs[3]);
    for (int i = 0; i < mode_count; i++) {
        printf("%.0f ", calcs[4 + i]);
    }
    printf("\n5. The weight value of %d occurs %d times within the cube.\n", check, (int)calcs[4 + mode_count]);
    free(calcs);
}

float *calc(int arr[SIZE][SIZE][SIZE], int freq, int size, int *mode_count)
{
    int value;
    int count = size * size * size;
    int occur[100] = {0};
    int sum = 0;
    int initial = arr[0][0][0];
    int max = initial;
    int min = initial;
    int all[count];
    int n = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                value = arr[i][j][k];
                all[n++] = value;
                sum += value;

                if (value > max)
                {
                    max = value;
                }

                if (value < min)
                {
                    min = value;
                }

                occur[value]++;
            }
        }
    }

    sort(all, count);
    float median = 0;

    if (count % 2 == 0)
    {
        median = (all[count / 2 - 1] + all[count / 2]) / 2.0;
    }
    else
    {
        median = all[count / 2];
    }

    int max_occur = 0;
    for (int i = 0; i < 100; i++) {
        if (occur[i] > max_occur) {
            max_occur = occur[i];
        }
    }

    *mode_count = 0;
    for (int i = 0; i < 100; i++) {
        if (occur[i] == max_occur) {
            (*mode_count)++;
        }
    }

    float *result = malloc((6 + *mode_count - 1) * sizeof(float));

    result[0] = (float)sum / count;
    result[1] = median;
    result[2] = min;
    result[3] = max;

    int mode_index = 4;
    for (int i = 0; i < 100; i++) {
        if (occur[i] == max_occur) {
            result[mode_index++] = i;
        }
    }

    result[4 + *mode_count] = occur[freq];

    return result;
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