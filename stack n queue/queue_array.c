#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void enqueue(int);
int dequeue();
int peek();
void display();

int a[MAX],front=-1,rear=-1;

int main()
{
int n,op;
while(1)
{
    printf("\n\nSelect:");
    printf("\n1.enqueue");
    printf("\n2.dequeue");
    printf("\n3.peek");
    printf("\n4.display");
    printf("\n5.exit");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            printf("\nenter a number=");
            scanf("%d",&n);
            enqueue(n);
            printf("\nQueue: ");
            display();
            break;

        case 2:
            n=dequeue();
            printf("\nremoved element: %d",n);
            printf("\nQueue: ");
            display();
            break;

        case 3:
            n=peek();
            printf("\nfirst element: %d",n);
            printf("\nQueue: ");
            display();
            break;

        case 4:
            printf("\nQueue: ");
            display();
            break;

        case 5:
            exit(1);

        default:
            printf("\ninvalid option");
    }
}
}

void enqueue(int n)
{
    if(rear==MAX-1)
    {
        printf("\nqueue full");
        return;
    }
    if(front==-1)
    {
        front++;
    }
    rear++;
    a[rear]=n;
}

int dequeue()
{
    if(front==-1 || front==rear+1)
    {
        printf("\nqueue empty");
        exit(1);
    }
    return a[front++];
}

int peek()
{
    if(front==-1 || front==rear+1)
    {
        printf("\nqueue empty");
        exit(1);
    }
    return a[front];
}

void display()
{
    int i;
    if(front==-1 || front==rear+1)
    {
        printf("\nqueue empty");
        return;
    }
    for(i=front;i<=rear;i++)
    {
        printf("%2d ",a[i]);
    }
}
