#include"s_header.h"
#include"create.c"
#include"display.c"

node *copy(node *);

int main()
{
node *h=NULL,*h_copy=NULL;
h=create(h);
display(h);
h_copy=copy(h);
printf("\nnew copied list");
display(h_copy);
}

node *copy(node *h)
{
    node *p,*c,*t,*q;
    if(h==NULL)
    {
        c=NULL;
        return c;
    }
    c=(node *)malloc(sizeof(node));
    c->data=h->data;
    c->next=NULL;
    q=c;
    p=h->next;
    while(p!=NULL)
    {
        t=(node*)malloc(sizeof(node));
        t->data=p->data;
        t->next=NULL;
        q->next=t;
        q=t;
        p=p->next;
    }
    return c;
}
