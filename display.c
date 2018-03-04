void display(struct node *start)
{
    struct node *p=start;
    printf("list: ");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
