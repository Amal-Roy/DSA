include <stdio.h>

int array[30];
int front = -1, rear = -1;
int limit;

void enqueue() {
    if ((front == 0 && rear == limit - 1) ) {
        printf("Overflow\n");
        return;
    }
else if ((rear + 1) % limit == front)

{
 printf("Overflow\n");
       
        return;
        }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % limit;
    }

    printf("Enter the element you want to insert: ");
    scanf("%d", &array[rear]);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
        return;
    }

  

    if (front == rear) {
        front = rear = -1;
    }
     else {
        front = (front + 1) % limit;
    }

    printf("The deleted element: %d\n", array[front]);
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", array[i]);
        if (i == rear)
            break;
        i = (i + 1) % limit;
    }
    printf("\n");
}

int main() {
    int next = 0;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    while (next != 3) {
        printf("\nEnter 1 for enqueue, 2 for dequeue, 3 for Exit: ");
        scanf("%d", &next);

        if(next==1){
        enqueue();
        display();
        }
        
        else if(next==2)
        {
        dequeue();
        display();
        }
        else if(next==3){
        printf("Exit");
        break;
        }    
        
        else{
        printf("Invalid");
        }    
    }

    return 0;
}


