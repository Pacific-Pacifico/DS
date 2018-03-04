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
node *ins_empty(node *);
node *ins_end(node *);
node *ins_after_pos(node *);
node *ins_before_pos(node *);

node *del_beg(node *);
node *del_end(node *);
node *del_between(node *);

int main()
{
node *h=NULL;
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
            display(h);
            break;

        case 3:
            printf("\nselect:");
            printf("\n1.insert at the beginning");
            printf("\n2.insert at the end");
            printf("\n3.insert after the entered position");
            printf("\n4.insert before the entered position");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    h=ins_beg(h);
                    break;

                case 2:
                    h=ins_end(h);
                    break;

                case 3:
                    h=ins_after_pos(h);
                    break;

                case 4:
                    h=ins_before_pos(h);
                    break;

                default:
                    printf("\ninvalid option");
            }
            break;

        case 4:
            printf("\nselect:");
            printf("\n1.delete at the beginning");
            printf("\n2.delete at the end");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    h=del_beg(h);
                    break;

                case 2:
                    h=del_end(h);
                    break;

                default:
                    printf("\ninvalid option");
            }
            break;

        case 5:
            exit(1);

        default:
            printf("\ninvalid selection");
    }
}
}

node *create(node *h)
{
    node *t,*p;
    char ch;
    t=(node *)malloc(sizeof(node));
    printf("\nenter data");
    scanf("%d",&t->data);
    t->prev=NULL;
    t->next=NULL;
    h=t;
    p=h;
    printf("\nenter more(y)??");
    ch=getche();
    while(ch=='y' || ch=='Y')
    {
        t=(node *)malloc(sizeof(node));
        printf("\nenter data");
        scanf("%d",&t->data);
        t->prev=p;
        t->next=NULL;
        p->next=t;
        p=t;
        printf("\nenter more(y)??");
        ch=getche();
    }
    return h;
}

void display(node *h)
{
    node *p;
    p=h;
    printf("\nlist: ");
    while(p!=NULL)
    {
        printf("%2d ",p->data);
        p=p->next;
    }
}

node *ins_beg(node *h)
{
    node *t;
    t=(node *)malloc(sizeof(node));
    printf("\nenter data=");
    scanf("%d",&t->data);
    t->prev=NULL;
    t->next=h;
    h->prev=t;
    h=t;
    return h;
}

node *ins_end(node *h)
{
    node *t,*p;
    p=h;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    t=(node *)malloc(sizeof(node));
    printf("\nenter data");
    scanf("%d",&t->data);
    t->next=NULL;
    t->prev=p;
    p->next=t;
    return h;
}

node *del_beg(node *h)
{
    node *t;
    t=h;
    h->next->prev=NULL;
    h=h->next;
    free(t);
    return h;
}

node *del_end(node *h)
{
    node *t,*p;
    p=h;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    t=p;
    p->prev->next=NULL;
    free(t);
    return h;
}

node *ins_after_pos(node *h)
{
    node *t,*p;
    int c=0,pos;
    printf("\nenter position=");
    scanf("%d",&pos);
    p=h;
    while(p->next!=NULL)
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
            return h;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\nposition not found");
    }
    return h;
}

node *ins_before_pos(node *h)
{
    node *t,*p;
    int c=0,pos;
    printf("\nenter position=");
    scanf("%d",&pos);
    p=h;
    while(p->next!=NULL)
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
            return h;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\nposition not found");
    }
    return h;
}

