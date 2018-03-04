struct node *create_list(struct node *start)
{
    int i,n,data;
    start=NULL;
    printf("how many elements u want to enter?\n");
    scanf("%d",&n);
    if(n==0)
    {
        return start;
    }
    printf("enter element=");
    scanf("%d",&data);
    start=ins_beg(start,data);
    for(i=1;i<n;i++)
    {
        printf("enter element=");
        scanf("%d",&data);
        start=ins_end(start,data);
    }
    return start;
}
