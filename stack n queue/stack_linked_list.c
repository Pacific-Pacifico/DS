#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *push(node *,int);
node *pop(node *);
int peek(node *);
void display(node *);

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
            h=push(h,n);
            printf("\nStack:");
            display(h);
            break;

        case 2:
            h=pop(h);
            printf("\nStack:");
            display(h);
            break;

        case 3:
            n=peek(h);
            printf("\nlast element=%d",n);
            printf("\nStack:");
            display(h);
            break;

        case 4:
            printf("\nStack:");
            display(h);
            break;

        case 5:
            exit(1);

        default:
            printf("\ninvalid option");
    }
}
}

node *push(node *h,int n)
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
    return h;
}

node *pop(node *h)
{
    node *t;
    if(h==NULL)
    {
        printf("\nstack empty");
        exit(1);
    }
    t=h;
    h=h->next;
    printf("\npopped element=%d",t->data);
    free(t);
    return h;
}

int peek(node *h)
{
    if(h==NULL)
    {
        printf("\nstack empty");
        exit(1);
    }
    return h->data;
}

void display(node *h)
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
