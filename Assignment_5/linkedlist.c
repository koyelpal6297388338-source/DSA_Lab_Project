/* Write a c program to implement of single linkedlist.*/
#include <stdio.h>
#include <stdlib.h>

struct link
{
    int n;
    struct link *next;
};

struct link *head = NULL;

void create()
{
    struct link *ptr, *temp;
    int data;

    ptr = (struct link *)malloc(sizeof(struct link));

    printf("Enter data: ");
    scanf("%d", &data);

    ptr->n = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
    }

    printf("Node added successfully.\n");
}

void display()
{
    struct link *temp;

    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->n);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Add Node\n");
        printf("2. Display Linked List\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}


