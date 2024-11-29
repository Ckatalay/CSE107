#include <stdio.h>

#define SIZE 10
char get_char(char *prompt);

int main(void)
{
    char students[SIZE][5] =
    {
        {'a', 'b', '0', '0', '5'},
        {'q', 'w', '5', '3', '9'},
        {'c', 'd', '9', '0', '1'},
        {'a', 'b', '8', '6', '6'},
        {'a', 'b', '2', '1', '3'},
        {'a', 'b', '1', '9', '8'},
        {'a', 'b', '4', '9', '9'},
        {'a', 'b', '6', '0', '7'},
        {'a', 'b', '7', '2', '5'},
        {'a', 'b', '3', '6', '2'},
    };
    char choice;

    do
    {
        choice = get_char("1. List all rows\n2. Find student with ID\n3. Highest grade by course ID\n4. Find number of students who takes courses\nInput: ");

        switch (choice)
        {
            case '1':
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        printf("%c ", students[i][j]);
                    }
                }
                printf("\n");
                break;
            
            case '2':
            {
                char student = get_char("Please input the student ID: ");
                int found = 0;

                for (int i = 0; i < SIZE; i++)
                {
                    if (students[i][2] == student)
                    {
                        found = 1;
                        printf("Student found: ");
                        for (int j = 0; j < 5; j++)
                        {
                            printf("%c ", students[i][j]);
                        }
                        printf("\n");
                        break;
                    }
                }
                if (!found)
                {
                    printf("Student with ID '%c' not found.\n", student);
                }
                break;
            }
            
            case '3':
            {
            int course = get_char("Please input course ID: ") - '0';
            if (course < 0 || course >= 5) 
            {
                printf("Invalid course ID. Please input a value between 0 and 4.\n");
                break;
            }

            int max = -1;
            for (int i = 0; i < SIZE; i++)
            {
                if (students[i][course] != '\0')
                {
                    if (max == -1 || students[i][4] > students[max][4])
                    {
                        max = i;
                    }
                }
            }

            if (max == -1)
            {
                printf("No students found for course ID %d.\n", course);
            }
            else
            {
                printf("Student with the highest grade in course ID %d: ", course);
                for (int j = 0; j < 5; j++)
                {
                    printf("%c ", students[max][j]);
                }
                printf("\n");
            }
            break;
            }

            case '4':
            {
                int course_count[10] = {0};

                for (int i = 0; i < SIZE; i++) 
                {
                    if (students[i][3] >= '0' && students[i][3] <= '9') 
                    {
                        int course_id = students[i][3] - '0';
                        course_count[course_id]++;
                    }
                }

                for (int i = 0; i < 10; i++)
                {
                    if (course_count[i] > 0)
                    {
                        printf("Course %d: %d student(s)\n", i, course_count[i]);
                    }
                }
                break;
            }
        }
    } while (choice != 'E' && choice != 'e');
}

char get_char(char *prompt)
{
    char c;
    printf("%s", prompt);
    while (1)
    {
        if (scanf(" %c", &c) == 1)
        {
            break;
        }
        else
        {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Try again: ");
        }
    }
    return c;
}