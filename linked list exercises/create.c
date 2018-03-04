node *create(node *h)
{
    node *p,*t;
    char ch;
    h=(node *)malloc(sizeof(node));
    printf("\nenter data");
    scanf("%d",&h->data);
    h->next=NULL;
    p=h;
    printf("\nenter more(y)?");
    ch=getche();
    while(ch=='y' || ch=='Y')
    {
        t=(node*)malloc(sizeof(node));
        printf("\nenter data");
        scanf("%d",&t->data);
        t->next=NULL;
        p->next=t;
        p=t;
        printf("\nenter more(y)?");
        ch=getche();
    }
    return h;
}
