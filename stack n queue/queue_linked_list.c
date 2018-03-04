#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void enqueue(int);
int dequeue();
int peek();
void display();

node *h=NULL;

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
    node *p,*t;
    t=(node *)malloc(sizeof(node));
    if(t==NULL)
    {
        printf("\nqueue full");
        return;
    }
    t->data=n;
    t->next=NULL;
    if(h==NULL)
    {
        h=t;
    }
    else
    {
        p=h;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}

int dequeue()
{
    node *t;
    int n;
    if(h==NULL)
    {
        printf("\nqueue empty");
        exit(1);
    }
    t=h;
    n=t->data;
    h=h->next;
    return n;
}

int peek()
{
    if(h==NULL)
    {
        printf("\nqueue empty");
        exit(1);
    }
    return h->data;
}

void display()
{
    node *p;
    p=h;
    while(p!=NULL)
    {
        printf("%2d ",p->data);
        p=p->next;
    }
}
