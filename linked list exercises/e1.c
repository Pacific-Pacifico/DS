#include"s_header.h"
#include"create.c"
#include"display.c"

int count(node *,int);

int main()
{
node *h=NULL;
int n,s;
h=create(h);
printf("\nenter number to search & count");
scanf("%d",&s);
n=count(h,s);
printf("\n%d occurred %d times in the list",s,n);
display(h);
}

int count(node *h,int s)
{
    node *p;
    int c;
    p=h;
    while(p!=NULL)
    {
        if(p->data==s)
        {
            c++;
        }
        p=p->next;
    }
    return c;
}
