#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[max];
int front = -1, rear = -1;
void Enqueue(int item);
void Dequeue();
void DisplayOfElements();
void Peek();
int IsFull();
int IsEmpty();
int main()
{
    while (1)
    {
        int c, num, check;
        printf("\n<-----------***----------->\n");
        printf("\n\tEnter one of the keys \n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display of Elements\n");
        printf("5.check if Empty\n");
        printf("6.check if full \n");
        printf("7.exit()\n");
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &num);
            Enqueue(num);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Peek();
            break;
        case 4:
            DisplayOfElements();
            break;
        case 5:
            check = IsEmpty();
            if (check == 1)
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 6:
            check = IsFull();
            if (check == 1)
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
            break;
            break;
        case 7:
            return 0;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}
void Enqueue(int data)
{
    if (IsFull())
    {
        printf("Queue Overflown\n");
        return;
    }
    if (IsEmpty())
    {
        front = 0;
    }
    if (rear == max - 1)
        rear = 0;
    else
        rear += 1;
    arr[rear] = data;
    printf("%d is inserted\n", data);
}
void Dequeue()
{
    if (IsEmpty())
    {
        printf("Queue Underflown\n");
        return;
    }
    int item = arr[front];
    printf("%d is removed\n", item);
    if (front == max - 1)
    {
        front = 0;
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
        return;
    }
    front += 1;
}
int IsFull()
{
    if (((front == 0) && (rear == max - 1)) || (front == rear + 1))
        return 1;
    else
        return 0;
}
int IsEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
void Peek()
{
    printf("Front Element: %d \n", arr[front]);
}
void DisplayOfElements()
{
    if (IsEmpty())
    {
        printf("Queue Underflown\n");
        return;
    }
    int pt = front;
    while (1)
    {
        printf("%d ", arr[pt]);
        if (pt == rear)
            return;
        if (pt == max - 1)
            pt = 0;
        else
            pt += 1;
        //if ((pt != max - 1) && (pt != rear))
    }
}
