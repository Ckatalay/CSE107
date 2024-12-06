#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    struct node *next;
} node;

int get_int(char *prompt);
node* create_node(int num);
void insert_after(node *prev, int val);

int main(void)
{
    int n = 0;

    while (n < 1)
    {
        n = get_int("Input the number of nodes: ");

        if (n < 1)
        {
            printf("Please input a positive integer.\n");
        }
    }

    node *list = create_node(n);
    node *current = list;
    node *prev = list;

    int m = 0;

    while (m < 1)
    {
        m = get_int("Insert after nth indice : ");

        if (m < 1)
        {
            printf("Please input a positive integer.\n");
        }
    }

    int value = get_int("Please input a value: ");

    for (int i = 0; i < m; i++)
    {
        prev = prev->next;
    }

    insert_after(prev, value);

    int j = 0;
    while (current != NULL)
    {
        printf("Data = %i\n", current->val);
        current = current->next;
        j++;
    }
    printf("Total number of nodes = %i\n", j);

    free(list);
}

node *create_node(int num)
{
    node *head = NULL;
    node *temp = NULL;

    for (int i = 0; i < num; i++)
    {
        node *element = (node *)malloc(sizeof(node));

        if (element == NULL)
        {
            printf("Memory allocation failed.\n");
            break;
        }

        char buffer[50];
        snprintf(buffer, sizeof(buffer), "Input data for %i: ", i);
        element->val = get_int(buffer);

        if (head == NULL) {
            head = element;
        } else {
            temp->next = element;
        }
        temp = element;
    }
    if (temp != NULL)
    {
        temp->next = NULL;
    }
    return head;
}

void insert_after(node *prev, int val)
{
    node *element = (node *)malloc(sizeof(node));
    if (element == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    element->val = val;
    node *temp = prev->next;
    prev->next = element;
    element->next = temp;
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