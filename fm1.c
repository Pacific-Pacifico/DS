#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;
node *create( )
{
node *h,*q,*r;
char ch;
h=(node*)malloc(sizeof(node));
printf("\n enter data");
scanf("%d",&h->data);
h->next=h->prev=NULL;
q=h;
printf("\n more y/n");
ch=getche();
while(ch=='y')
{
r=(node*)malloc(sizeof(node));
printf("\n enter data");
scanf("%d",&r->data);
r->next=NULL;
r->prev=q;
q->next=r;
q=r;
printf("\n more y/n");
ch=getche();
}
return h;
}

void traverse(node *h)
{
node *p;
p=h;
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}

void main()
{
node *h;
h=create();
printf("\nentered list: ");
traverse(h);
}
