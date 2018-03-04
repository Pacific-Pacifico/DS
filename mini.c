#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node*next;
}
node;
node * create()
{
node *h,*q,*r;
char ch;
h=(node*) malloc(sizeof(node));
printf("\n enter data");
scanf("%d",&h->data);
h->next=NULL;
q=h;
printf("\n more (Y/N);");
ch=getche();
while(ch=='Y' || ch=='y')
{
r=(node*)malloc(sizeof(node));
printf("\nenter data:");
scanf("%d",&r->data);
r->next=NULL;
q->next=r;
q=r;
printf("\n more(Y/N);");
ch=getche();
}
return h;
}

void traverse(node *h)
{
node*s;
s=h;
while(s!=NULL)
{
printf("%5d ",s->data);
s=s->next;
}
}

void main()
{
node*h;
h=create();
printf("\n");
traverse(h);
}
