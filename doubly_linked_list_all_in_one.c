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
node *ins_after(node *);
node *ins_before(node *);
node *ins_pos(node *);

node *del_beg(node *);
node *del_empty(node *);
node *del_only(node *);
node *del_end(node *);
node *del_between(node *);
node *del_pos(node *);

int main()
{
node *h=NULL;
int op,op1,op2;
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
            printf("\n2.insert in an empty list");
            printf("\n3.insert at the end");
            printf("\n4.insert after/before an element");
            printf("\n5.insert according to position");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    h=ins_beg(h);
                    break;

                case 2:
                    h=ins_empty(h);
                    break;

                case 3:
                    h=ins_end(h);
                    break;

                case 4:
                    printf("\nselect:");
                    printf("\n1.insert after an element");
                    printf("\n2.insert before an element");
                    scanf("%d",&op2);
                    switch(op2)
                    {
                        case 1:
                            h=ins_after(h);
                            break;

                        case 2:
                            h=ins_before(h);
                            break;

                        default:
                            printf("\ninvalid option");
                    }
                    break;

                case 5:
                    break;

                default:
                    printf("\ninvalid option");
            }
            break;

        case 4:
            printf("\nselect:");
            printf("\n1.delete at the beginning");
            printf("\n2.delete only single node present in the list");
            printf("\n3.delete at the end");
            printf("\n4.delete an element in between the list");
            printf("\n5.delete according to position");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    h=del_beg(h);
                    break;

                case 2:
                    h=del_only(h);
                    break;

                case 3:
                    h=del_end(h);
                    break;

                case 4:
                    h=del_between(h);
                    break;

                case 5:
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

node *ins_empty(node *h)
{
    if(h==NULL)
    {
        node *t;
        t=(node *)malloc(sizeof(node));
        printf("\nenter data=");
        scanf("%d",&t->data);
        t->prev=NULL;
        t->next=NULL;
        h=t;
    }
    else if(h!=NULL)
    {
        printf("\nlist must be empty to insert in an empty list");
    }
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

node *ins_after(node *h)
{
    node *t,*p;
    int item;
    printf("\nenter item after which to enter data=");
    scanf("%d",&item);
    p=h;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            t=(node *)malloc(sizeof(node));
            printf("\nenter data=");
            scanf("%d",&t->data);
            t->prev=p;
            if(p->next!=NULL)
            {
                t->next=p->next;
                p->next->prev=t;
            }
            p->next=t;
            return h;
        }
        p=p->next;
    }
    printf("\nelement after which to insert not found!!");
    return h;
}

node *ins_before(node *h)
{
    node *p,*t;
    int item;
    printf("\nenter item before which to enter data=");
    scanf("%d",&item);
    if(h->data==item)
    {
        t=(node *)malloc(sizeof(node));
        printf("\nenter data");
        scanf("%d",&t->data);
        t->prev=NULL;
        t->next=h;
        h->prev=t;
        h=t;
        return h;
    }
    p=h;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            t=(node *)malloc(sizeof(node));
            printf("\nenter data");
            scanf("%d",&t->data);
            t->prev=p->prev;
            t->next=p;
            p->prev->next=t;
            p->prev=t;
            return h;
        }
        p=p->next;
    }
    printf("\nelement before which to insert not found!!");
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

node *del_only(node *h)
{
    node *t;
    t=h;
    h=NULL;
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

node *del_between(node *h)
{
    node *t,*p;
    int item;
    p=h;
    printf("\nenter element to delete");
    scanf("%d",&item);
    while(p!=NULL)
    {
        if(p->data==item)
        {
            t=p;
            p->next->prev=p->prev;
            p->prev->next=p->next;
            free(t);
            return h;
        }
        p=p->next;
    }
    printf("\nelement to be deleted not found");
    return h;
}

