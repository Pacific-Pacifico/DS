void display(node *h)
{
    node *p;
    p=h;
    printf("\nList: ");
    while(p!=NULL)
    {
        printf("%2d ",p->data);
        p=p->next;
    }
}
