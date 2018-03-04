void search(struct node *start,int item)
{
    struct node *p=start;
    int pos=0,f=0;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            f=1;
            printf("found at position=%d\n",(pos+1));
        }
        p=p->next;
        pos++;
    }
    if(!f)
    {
        printf("not found\n");
    }
}
