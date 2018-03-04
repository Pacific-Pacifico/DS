#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *create(node *);
void display(node *);
node *ins_beg(node *);
node *ins_end(node *);
node *ins_apos(node *);
node *ins_bpos(node *);
node *del_beg(node *);
node *del_end(node *);
node *del_pos(node *);
node *reverse(node *);
node *concat(node *,node *);
node *ssort(node *);
node *bsort(node *);
node *merge(node *,node *);

int main()
{
node *h=NULL,*h1=NULL;
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
    printf("\n10.reverse");
    printf("\n11.concatenate two lists");
    printf("\n12.sort using selection sort");
    printf("\n13.sort using bubble sort");
    printf("\n14.merge two sorted arrays");
    printf("\n15.exit");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            h=create(h);
            break;

        case 2:
            display(h);
            break;

        case 3:
            h=ins_beg(h);
            break;

        case 4:
            h=ins_end(h);
            break;

        case 5:
            h=ins_apos(h);
            break;

        case 6:
            h=ins_bpos(h);
            break;

        case 7:
            h=del_beg(h);
            break;

        case 8:
            h=del_end(h);
            break;

        case 9:
            h=del_pos(h);
            break;

        case 10:
            h=reverse(h);
            break;

        case 11:
            printf("\ncreate another list to concatenate with current list");
            h1=create(h1);
            printf("\nentered list");
            display(h1);
            printf("\nlist before concatenation");
            display(h);
            h=concat(h,h1);
            printf("\n\nConcatenated list");
            display(h);
            break;

        case 12:
            h=ssort(h);
            break;

        case 13:
            h=bsort(h);
            break;

        case 14:
            break;

        case 15:
            exit(1);

        default:
            printf("\nwrong choice");
    }
}
}

node *create(node *h)
{
    node *p,*t;
    char ch;
    h=(node *)malloc(sizeof(node));
    printf("\nenter data=");
    scanf("%d",&h->data);
    h->prev=h;
    h->next=h;
    p=h;
    printf("\nenter more?(y)");
    ch=getche();
    while(ch=='Y' || ch=='y')
    {
        t=(node *)malloc(sizeof(node));
        printf("\nenter data=");
        scanf("%d",&t->data);
        t->prev=p;
        t->next=h;
        p->next=t;
        p=t;
        printf("\nenter more?(y)");
        ch=getche();
    }
    return h;
}

void display(node *h)
{
    node *p;
    if(h==NULL)
    {
        printf("\nlist is empty");
        return;
    }
    printf("\nList: ");
    p=h;
    while(p->next!=h)
    {
        printf("%2d ",p->data);
        p=p->next;
    }
    printf("%2d ",p->data);
    printf("\nList in backward form: ");
    while(p!=h)
    {
        printf("%2d ",p->data);
        p=p->prev;
    }
    printf("%2d ",p->data);
}

node *ins_beg(node *h)
{
    node *p,*t;
    p=h;
    while(p->next!=h)
    {
        p=p->next;
    }
    t=(node *)malloc(sizeof(node));
    printf("\nenter data=");
    scanf("%d",&t->data);
    t->prev=p;
    t->next=p->next;
    p->next->prev=t;
    p->next=t;
    h=t;
    return h;
}

node *ins_end(node *h)
{
    node *p,*t;
    p=h;
    while(p->next!=h)
    {
        p=p->next;
    }
    t=(node *)malloc(sizeof(node));
    printf("\nenter data=");
    scanf("%d",&t->data);
    t->prev=p;
    t->next=h;
    h->prev=t;
    p->next=t;
    return h;
}

node *ins_apos(node *h)
{
    node *p,*t;
    int pos,c=0;
    printf("\nenter position after which u want to enter data=");
    scanf("%d",&pos);
    p=h;
    while(p->next!=h)
    {
        c++;
        if(c==pos)
        {
            t=(node *)malloc(sizeof(node));
            printf("\nenter data=");
            scanf("%d",&t->data);
            t->prev=p;
            t->next=p->next;
            p->next->prev=t;
            p->next=t;
            break;
        }
        p=p->next;
    }
    return h;
}

node *ins_bpos(node *h)
{
    node *p,*t;
    int pos,c=0;
    printf("\nenter position before which u want to enter data=");
    scanf("%d",&pos);
    p=h;
    while(p->next!=h)
    {
        c++;
        if(c==pos-1)
        {
            t=(node *)malloc(sizeof(node));
            printf("\nenter data=");
            scanf("%d",&t->data);
            t->prev=p;
            t->next=p->next;
            p->next->prev=t;
            p->next=t;
            break;
        }
        p=p->next;
    }
    return h;
}

node *del_beg(node *h)
{
    node *p,*t;
    if(h==NULL)
    {
        printf("\nlist is empty");
        return h;
    }
    p=h;
    while(p->next!=h)
    {
        p=p->next;
    }
    t=p->next;
    t->next->prev=p;
    p->next=t->next;
    h=p->next;
    free(t);
    return h;
}

node *del_end(node *h)
{
    node *p,*t;
    if(h==NULL)
    {
        printf("\nlist is empty");
        return h;
    }
    p=h;
    while(p->next->next!=h)
    {
        p=p->next;
    }
    t=p->next;
    t->next->prev=p;
    p->next=h;
    free(t);
    return h;
}

node *del_pos(node *h)
{
    node *p,*t;
    int pos,c=0;
    printf("\nenter position at which u want to delete data=");
    scanf("%d",&pos);
    p=h;
    while(p->next!=h)
    {
        c++;
        if(c==pos-1)
        {
            t=p->next;
            t->next->prev=p;
            p->next=t->next;
            free(t);
        }
        p=p->next;
    }
    return h;
}

node *reverse(node *h)
{
    node *p,*q,*r;
    r=h;
    while(r->next!=h)
    {
        r=r->next;
    }
    p=h;
    q=h->next;
    p->prev=q;
    p->next=r;
    while(q!=h)
    {
        q->prev=q->next;
        q->next=p;
        p=q;
        q=q->prev;
    }
    h=p;
    return h;
}

node *concat(node *a,node *b)
{
    node *p,*q,*t;
    p=a;
    while(p->next!=a)
    {
        p=p->next;
    }
    p->next=b;
    b->prev=p;
    q=b;
    while(q->next!=b)
    {
        q=q->next;
    }
    q->next=a;
    a->prev=q;
    return a;
}

node *ssort(node *h)
{
    node *p,*q;
    int temp;
    for(p=h;p->next!=h;p=p->next)
    {
        for(q=p->next;q!=h;q=q->next)
        {
            if(q->data<p->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
    return h;
}

node *bsort(node *h)
{
    node *p,*q,*end;
    int temp;
    for(end=h;end!=h->next;end=q)
    {
        for(p=h;p->next!=end;p=p->next)
        {
            q=p->next;
            if(q->data<p->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
    return h;
}

