
#include <stdio.h>

int front = -1, rear = -1, deque[50];

void display(int limit)
{
    int i = front;
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements:\n");
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % limit;
    }
    printf("\n");
}

void insertFront(int value, int limit)
{
    if ((front == 0 && rear == limit - 1) || (front == rear + 1))
    {
        printf("Deque is full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = limit - 1;
    }
    else
    {
        front--;
    }
    deque[front] = value;
}

void insertRear(int value, int limit)
{
    if ((front == 0 && rear == limit - 1) || (front == rear + 1))
    {
        printf("Deque is full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == limit - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = value;
}

void deleteFront(int limit)
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted element from front: %d\n", deque[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == limit - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear(int limit)
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted element from rear: %d\n", deque[rear]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = limit - 1;
    }
    else
    {
        rear--;
    }
}

int main()
{
    int limit, choice =0 , val;
    printf("Enter the size of deque: ");
    scanf("%d", &limit);

    while (choice != 5)
    {
        printf("\nMenu:\n");
        printf("1 - Insert Front\n");
        printf("2 - Insert Rear\n");
        printf("3 - Delete Front\n");
        printf("4 - Delete Rear\n");
        printf("5 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the element to insert at front: ");
            scanf("%d", &val);
            insertFront(val, limit);
            display(limit);
        }
        else if (choice == 2)
        {
            printf("Enter the element to insert at rear: ");
            scanf("%d", &val);
            insertRear(val, limit);
            display(limit);
        }
        else if (choice == 3)
        {
            deleteFront(limit);
            display(limit);
        }
        else if (choice == 4)
        {
            deleteRear(limit);
            display(limit);
        }
        else if (choice == 5)
        {
            printf("Exiting...\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
