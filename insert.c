#include"node.h"
struct node *ins_beg(struct node *start,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=start;
    start=temp;
    return start;
}

struct node *ins_end(struct node *start,int data)
{
    struct node *p,*temp;
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=NULL;
    p->next=temp;
    return start;
}

struct node *ins_after(struct node *start,int data)
{
}

struct node *ins_before(struct node *start,int data)
{
}

struct node *ins_pos(struct node *start,int data,int pos)
{
}
