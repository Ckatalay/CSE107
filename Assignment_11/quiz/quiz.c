#include <stdio.h>

int main(void)
{
    FILE *ptr = fopen("./student.txt", "r");
    int buffer;
    int sum = 0;
    int count = 0;
    while (fscanf(ptr, "%i", &buffer) == 1)
    {
        sum += buffer;
        count++;
    }
    fclose(ptr);
    printf("Average: %.2f\n", (float)sum / (float)count);
}