
#include <stdio.h>
#define maxSize 100

int QUEUE[maxSize];
int front = -1, rear = -1;

void Insertion() {
    int item;
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        printf("Enter the item: ");
        scanf("%d", &item);
        QUEUE[rear] = item;
    }
   
    else if (rear == maxSize - 1) {
        printf("Queue Overflow\n");
    }
    else {
        rear++;
        printf("Enter the item: ");
        scanf("%d", &item);
        QUEUE[rear] = item;
    }
}

void Deletion() {
   
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        front = -1;
        rear = -1;
    }
    else {
        printf("Deleted element is %d\n", QUEUE[front]);
        front++;
    }
}
void Display() {
    if (front == -1 || front > rear)
    {
      printf("Queue is empty");
     }
     else
     {
      printf("elements after deletion ");
      for(int j=front;j<= rear;j++)
      {
       printf("%d", QUEUE[j]);
       printf("\n");
      }
     }
     }
int main()
{
  int i,n,m;
  printf("Enter the values of n and m:");
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
  {
    Insertion();
  }
   for(i=1;i<=m;i++)
   {
    Deletion();
   }  
   Display();
    return 0;
}
