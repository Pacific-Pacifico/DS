#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int main()
{
node *h=NULL;
int op;
while(1)
{
    printf("\n\nselect");
    printf("\n1.create");
    printf("\n2.display");
    printf("\n3.insert in the beginning");
    printf("\n4.insert in the end");
    printf("\n5.insert after position");
    printf("\n6.insert before position");
    printf("\n7.delete in the beginning");
    printf("\n8.delete in the end");
    printf("\n9.delete at the position");
    printf("\n10.exit");
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
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            break;

        case 10:
            break;

        default:
            printf("\nwrong choice");
    }
}
}
