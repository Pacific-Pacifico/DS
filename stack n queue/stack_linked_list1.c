#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void push(int);
int pop();
int peek();
void display();

node *h=NULL;

int main()
{
node *h=NULL;
int n,op;
while(1)
{
    printf("\n\nSelect:");
    printf("\n1.push");
    printf("\n2.pop");
    printf("\n3.peek");
    printf("\n4.display");
    printf("\n5.exit");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            printf("\nenter a number=");
            scanf("%d",&n);
            push(n);
            printf("\nStack:");
            display();
            break;

        case 2:
            n=pop();
            printf("\npopped element=%d",n);
            printf("\nStack:");
            display();
            break;

        case 3:
            n=peek();
            printf("\nlast element=%d",n);
            printf("\nStack:");
            display();
            break;

        case 4:
            printf("\nStack:");
            display();
            break;

        case 5:
            exit(1);

        default:
            printf("\ninvalid option");
    }
}
}

void push(int n)
{
    node *t;
    t=(node *)malloc(sizeof(node));
    if(t==NULL)
    {
        printf("\nstack full");
        return;
    }
    t->data=n;
    t->next=h;
    h=t;
}

int pop()
{
    node *t;
    int n;
    if(h==NULL)
    {
        printf("\nstack empty");
        exit(1);
    }
    t=h;
    h=h->next;
    n=t->data;
    free(t);
    return n;
}

int peek()
{
    if(h==NULL)
    {
        printf("\nstack empty");
        exit(1);
    }
    return h->data;
}

void display()
{
    node *p;
    if(h==NULL)
    {
        printf("\nstack empty");
        return;
    }
    p=h;
    while(p!=NULL)
    {
        printf("\n%d",p->data);
        p=p->next;
    }
}
