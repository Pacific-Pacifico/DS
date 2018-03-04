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

    node *rev_list(node *h)
    {

        node *a,*b,*c;
        a=NULL;
        b=h;
        while(b!=NULL)
        {
            c=b->next;
            b->next=a;
            a=b;
            b=c;
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
