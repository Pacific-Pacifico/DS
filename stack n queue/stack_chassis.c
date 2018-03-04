#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void push(int);
int pop();
int peek();
void display(int[]);

int top=-1;

int main()
{
int a[MAX],op;
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
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            exit(1);

        default:
            printf("\ninvalid option");
    }
}
}
