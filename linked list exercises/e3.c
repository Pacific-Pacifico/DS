#include"s_header.h"
#include"create.c"
#include"display.c"

int is_identical(node *,node *);

int main()
{
node *h1=NULL,*h2=NULL;
h1=create(h1);
display(h1);
h2=create(h2);
display(h2);
if(is_identical(h1,h2))
    printf("\ntwo lists are identical");
else
    printf("\ntwo lists are not identical");
}

int is_identical(node *h1,node *h2)
{
    node *p1=h1,*p2=h2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data!=p2->data)
        {
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }
    if(p1==NULL && p2==NULL)
        return 1;
    else
        return 0;
}
