#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
 node *create()
{
    node *h,*q,*r;
    char ch;
    h=(node*)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&h->data);
    h->next=NULL;
    q=h;
    printf("more?(y/n)");
    ch=getche();
    while(ch=='y')
    {
        r=(node*)malloc(sizeof(node));
        printf("Enter data");
        scanf("%d",&r->data);
        r->next=NULL;
        q->next=r;
        q=r;
        printf("more?(y/n)");
        ch=getche();
    }
    return h;
    }

node *merge(node *a,node *b)
{
    node *p,*q,*t;
    p=a;
    q=b;
    while(p!=NULL && q!=NULL)
    {
        while(p->data<=q->data && p!=NULL && q!=NULL)
        {
            t=p;
            p=p->next;
        }
        t->next=q;
        while(q->data<=p->data && p!=NULL && q!=NULL)
        {
            t=q;
            q=q->next;
        }
        t->next=p;
    }
    if(a->data<b->data)
        return a;
    else
        return b;
}


void traverse(node *h)
{
    node *s;
    s=h;
    while(s!=NULL)
    {
        printf("%5d",s->data);
        s=s->next;
    }
}
void main()
{

    node *h=NULL,*h1=NULL;
    printf("\ncreating list 1");
    h=create();
    traverse(h);
    printf("\ncreating list 2");
    h1=create();
    traverse(h1);
    h=merge(h,h1);
    traverse(h);
}
