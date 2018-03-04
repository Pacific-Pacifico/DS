#include"s_header.h"
#include"create.c"
#include"display.c"

void min_max(node *,int *,int *);

int main()
{
node *h=NULL;
int min,max;
h=create(h);
min_max(h,&min,&max);
printf("\nmin=%d \nmax=%d",min,max);
display(h);
}

void min_max(node *h,int *min,int *max)
{
    node *p;
    *min=*max=h->data;
    p=h->next;
    while(p!=NULL)
    {
        if(p->data<*min)
        {
            *min=p->data;
        }
        if(p->data>*max)
        {
            *max=p->data;
        }
        p=p->next;
    }
}
