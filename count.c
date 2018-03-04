void count(struct node *start)
{
    int c=0;
    struct node *p=start;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    printf("number of elements=%d\n",c);
}
