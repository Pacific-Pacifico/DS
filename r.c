#include<stdio.h>

#include<malloc.h>

struct node
{
int data;
struct node *link;
};
void add(struct node**,int);
void display (struct node*);
int count(struct node*);
void main()
{
struct node*p;
p=NULL;
add(&p,5);
add(&p,1);
add(&p,6);
add(&p,4);
add(&p,7);
display(p);
printf("\n No of elements in  linked list=%d",count(p));
}
void add(struct node **q,int num)
{
    struct node*r,*temp=*q;
    r=malloc(sizeof(struct node));
    r->data=num;
if(*q==NULL||(*q)->data>num)
{
*q=r;
(*q)->link=temp;
}
else
{
while(temp!=NULL)
{
if(temp->data<=num &&(temp->link->data>num|| temp->link==NULL))
{
r->link=temp->link;
temp->link=r;
return;
}
temp=temp->link;
}
}
}
void display(struct node *q)
{
printf("\n");
while(q!=NULL)
{
printf("%d",q-> data);
q=q->link;
}
}
int count(struct node *q)
{
int c=0;
while(q!=NULL)
{
q=q->link;
c++;
}
return c;
}


