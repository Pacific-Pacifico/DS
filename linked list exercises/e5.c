#include"s_header.h"
#include"create.c"
#include"display.c"

node *rev_copy(node *);

int main()
{
node *h=NULL,*h_rev=NULL;
h=create(h);
display(h);
h_rev=rev_copy(h);
display(h_rev);
}

node *rev_copy(node *h)
{

}
