#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
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

    node *rev_list(node *h)
    {

        node *a,*b,*c;
        a=h;
        b=a->next;
        c=b->next;
        h->next=NULL;
        h->prev=b;
        while(b!=NULL)
        {
            b->next=a;
            b->prev=c;
            a=b;
            b=c;
            c=c->next;
        }
                h=a;
                return h;

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

    node *h;
    h=create();
    traverse(h);
    printf("\nAfter reversing:-");
    h=rev_list(h);
    traverse(h);

}
