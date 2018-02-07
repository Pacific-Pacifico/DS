#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *create(node *h);

int main()
{
node *h;
int op,op1;
while(1)
{
    printf("\n\nselect the required option");
    printf("\n1.create list");
    printf("\n2.display");
    printf("\n3.insert");
    printf("\n4.delete");
    printf("\n5.exit");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            h=create(h);
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
            printf("\ninvalid selection");
    }
}
}

