#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void push(int);
int pop();
int peek();
void display();

int a[MAX],top=-1;

int main()
{
int op,n;
while(1)
{
    printf("\nSelect:");
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
            printf("\ntop=%d",top);
            printf("\nStack:");
            display(a);
            break;

        case 2:
            n=pop();
            printf("\npopped element=%d",n);
            printf("\ntop=%d",top);
            printf("\nStack:");
            display(a);
            break;

        case 3:
            n=peek();
            printf("\nlast element=%d",n);
            printf("\ntop=%d",top);
            printf("\nStack:");
            display(a);
            break;

        case 4:
            printf("\nStack:");
            display(a);
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
    if(top==MAX-1)
    {
        printf("\nstack full");
        return ;
    }
    top++;
    a[top]=n;
}

int pop()
{
    if(top==-1)
    {
        printf("\nstack empty");
        exit(1);
    }
    else
    {
        return a[top--];
    }
}

int peek()
{
    if(top==-1)
    {
        printf("\nstack empty");
        exit(1);
    }
    else
    {
        return a[top];
    }
}

void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("\n%d",a[i]);
    }
}
