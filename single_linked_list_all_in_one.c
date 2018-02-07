#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_default(struct node *);
struct node *create(struct node *);
void display(struct node *);
void search(struct node *);
int count(struct node *);
struct node *ins_beg(struct node *);
struct node *ins_end(struct node *);
struct node *ins_after(struct node *);
struct node *ins_before(struct node *);
struct node *ins_posa(struct node *);
struct node *ins_posb(struct node *);
struct node *ins_pos(struct node *);
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *del_pos(struct node *);
struct node *del_item(struct node *);
struct node *reverse(struct node *);
struct node *concat(struct node *,struct node *);
struct node *call_concat(struct node *);
struct node *ssort(struct node *);
struct node *bsort(struct node *);
struct node *my_ssort(struct node *);   //my created
struct node *my_bsort(struct node *);     //sorting
void find_min(struct node *);
void find_max(struct node *);
struct node *my_merge(struct node *,struct node *);
struct node *merge(struct node *,struct node *);

int main()
{
struct node *start=NULL;
struct node *s1=NULL,*s2=NULL;  //for merging
int op,op1;
while(1)
{
printf("\n\nselect the required option");
printf("\n1.create list");
printf("\n2.display");
printf("\n3.search an element");
printf("\n4.count total elements");
printf("\n5.insert");
printf("\n6.delete");
printf("\n7.reverse");
printf("\n8.concatenate lists");
printf("\n9.sort");
printf("\n10.find min or max");
printf("\n11.merge");
printf("\n12.exit");
scanf("%d",&op);
switch(op)
{
    case 1:
            printf("\nselect:");
            printf("\n1.create default list");
            printf("\n2.create ur own list");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    start=create_default(start);
                    break;

                case 2:
                    start=create(start);
                    break;

                default:
                    printf("invalid entry!!");
            }
            break;

    case 2:
            display(start);
            break;
    case 3:
            search(start);
            break;
    case 4:
            printf("\nnumber of elments=%d",count(start));
            break;
    case 5:
            printf("\nselect:");
            printf("\n1.insert at the beginning");
            printf("\n2.insert at the end");
            printf("\n3.insert after element");
            printf("\n4.insert before element");
            printf("\n5.insert at position");
            printf("\n6.insert after position");
            printf("\n7.insert before position");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    start=ins_beg(start);
                    break;

                case 2:
                    start=ins_end(start);
                    break;

                case 3:
                    start=ins_after(start);
                    break;

                case 4:
                    start=ins_before(start);
                    break;

                case 5:
                    start=ins_pos(start);
                    break;

                case 6:
                    start=ins_posa(start);
                    break;

                case 7:
                    start=ins_posb(start);
                    break;

                default:
                    printf("invalid entry");
            }
            break;
    case 6:
            printf("\nselect:");
            printf("\n1.delete at the beginning");
            printf("\n2.delete at the end");
            printf("\n3.delete at the position");
            printf("\n4.search and delete the element");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    start=del_beg(start);
                    break;

                case 2:
                    start=del_end(start);
                    break;

                case 3:
                    //start=del_pos(start);
                    break;

                case 4:
                    start=del_item(start);
                    break;

                default:
                    printf("invalid entry");
            }
            break;
    case 7:
            start=reverse(start);
            break;

    case 8:
            start=call_concat(start);
            break;

    case 9:
            printf("\nselect:");
            printf("\n1.use selection sort");
            printf("\n2.use bubble sort");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    printf("\ncurrent linked list: ");
                    display(start);
                    start=ssort(start);
                    printf("\nsorted linked list: ");
                    display(start);
                    break;

                case 2:
                    printf("\ncurrent linked list: ");
                    display(start);
                    start=bsort(start);
                    printf("\nsorted linked list: ");
                    display(start);
                    break;

                default:
                    printf("invalid entry");
            }
            break;

    case 10:
            printf("\nselect:");
            printf("\n1.find min");
            printf("\n2.find max");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    find_min(start);
                    break;

                case 2:
                    find_max(start);
                    break;

                default:
                    printf("invalid entry");
            }
            break;

    case 11:
            printf("\nselect:");
            printf("\n1.merge two sorted lists");
            printf("\n2.merge two unsorted lists");
            printf("\n3.merge by concatenating and then sorting");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:
                    printf("\ncreate list 1: ");
                    s1=create(s1);

                    printf("\ncreate list 2: ");
                    s2=create(s2);

                    printf("\n\nlist 1:");
                    display(s1);
                    printf("\n\nlist 2:");
                    display(s2);

                    printf("\n\nmerged linked list: ");
                    s1=merge(s1,s2);
                    display(s1);
                    break;

                case 2:
                    printf("\ncreate list 1: ");
                    s1=create(s1);
                    printf("\nlist 1:");
                    display(s1);

                    printf("\ncreate list 2: ");
                    s2=create(s2);
                    printf("\nlist 2:");
                    display(s2);

                    printf("\n\nsorted list 1");
                    s1=ssort(s1);
                    display(s1);

                    printf("\n\nsorted list 2");
                    s2=ssort(s2);
                    display(s2);

                    printf("\n\nmerged linked list: ");
                    s1=merge(s1,s2);
                    display(s1);
                    break;

            case 3:
                    printf("\ncreate list 1: ");
                    s1=create(s1);
                    printf("\nlist 1:");
                    display(s1);

                    printf("\ncreate list 2: ");
                    s2=create(s2);
                    printf("\nlist 2:");
                    display(s2);

                    printf("\n\nsorted list 1");
                    s1=ssort(s1);
                    display(s1);

                    printf("\n\nsorted list 2");
                    s2=ssort(s2);
                    display(s2);

                    printf("\n\nmerged linked list: ");
                    s1=my_merge(s1,s2);
                    display(s1);
                    break;

                default:
                    printf("invalid entry");
            }
            break;


    case 12:
            printf("exiting....");
            exit(1);
    default:
        printf("\ninvalid choice");
}
}
}

struct node *create_default(struct node *start)
{
    struct node *temp,*p;
    int min,max,i;
    printf("\nenter min value:");
    scanf("%d",&min);
    printf("\nenter max value:");
    scanf("%d",&max);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=min;
    temp->next=NULL;
    start=temp;
    p=start;
    for(int i=min+1;i<=max;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=i;
        temp->next=NULL;
        p->next=temp;
        p=p->next;
    }
    return start;
}

struct node *create(struct node *start)
{
    struct node *temp,*p;
    char ch;
    start=ins_beg(start);
    printf("\nadd more??");
    ch=getche();
    while(ch=='Y' || ch=='y')
    {
        start=ins_end(start);
        printf("\nadd more??");
        ch=getche();
    }
    printf("\n ur list has been created");
    return start;
}

void display(struct node *start)
{
    struct node *p;
    p=start;
    if(start==NULL)
    {
        printf("list is empty");
        return;
    }
    printf("\nelements:");
    while(p!=NULL)
    {
        printf("%5d ",p->data);
        p=p->next;
    }
}

void search(struct node *start)
{
    struct node *p=start;
    int pos=0,ser,f=0;
    printf("\nenter element to search=");
    scanf("%d",&ser);
    while(p!=NULL)
    {
        pos++;
        if(p->data==ser)
        {
            f=1;
            printf("found @ position=%d",pos);
        }
        p=p->next;
    }
    if(!f)
        printf("\nelement not found");
}

int count(struct node *start)
{
    struct node *p=start;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

struct node *ins_beg(struct node *start)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nenter element to insert at the beginning=");
    scanf("%d",&temp->data);
    temp->next=start;
    start=temp;
    return start;
}

struct node *ins_end(struct node *start)
{
    struct node *temp,*p;
    p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nenter element to insert at the end=");
    scanf("%d",&temp->data);
    temp->data;
    temp->next=NULL;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    return start;
}


struct node *ins_after(struct node *start)
{
    struct node *temp,*p;
    int elem;

    printf("\nenter element after which enter data=");
    scanf("%d",&elem);
    p=start;
    while(p!=NULL)
    {
        if(p->data==elem)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nenter element to insert=");
            scanf("%d",&temp->data);
            temp->next=p->next;
            p->next=temp;
            return start;
        }
        p=p->next;
    }
    printf("\nelement not found");
    return start;
}

struct node *ins_before(struct node *start)
{
    struct node *temp,*p;
    if(start==NULL)
    {
        printf("list is empty");
        return start;
    }
    int elem;
    printf("\nenter element before which enter data=");
    scanf("%d",&elem);
    if(start->data==elem)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nenter element to insert=");
        scanf("%d",&temp->data);
        temp->next=start;
        start=temp;
        return start;
    }
    p=start;
    while(p->next!=NULL)
    {
        if(p->next->data==elem)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nenter element to insert=");
            scanf("%d",&temp->data);
            temp->next=p->next;
            p->next=temp;
            return start;
        }
        p=p->next;
    }
    printf("\nelement not found");
    return start;
}

struct node *ins_pos(struct node *start)
{
    struct node *temp,*p;
    int pos,c;
    p=start;
    printf("\nenter position=");
    scanf("%d",&pos);
    if(pos==1)
    {
        start=ins_beg(start);
        return start;
    }
    for(c=1;c<pos-1 && p!=NULL;c++)
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\nposition not found");
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nenter element to insert=");
        scanf("%d",&temp->data);
        temp->next=p->next;
        p->next=temp;
    }
    return start;
}

struct node *ins_posa(struct node *start)
{
    struct node *temp,*p;
    int pos,c=0;
    printf("\nenter position=");
    scanf("%d",&pos);
    p=start;
    while(p!=NULL)
    {
        c++;
        if(c==pos)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nenter element to insert=");
            scanf("%d",&temp->data);
            temp->next=p->next;
            p->next=temp;
            break;
        }
        p=p->next;
    }
    return start;
}

struct node *ins_posb(struct node *start)
{
    struct node *temp,*p;
    int pos,c=0;
    printf("\nenter position=");
    scanf("%d",&pos);
    if(pos==1)
    {
        start=ins_beg(start);
        return start;
    }
    p=start;
    while(p!=NULL)
    {
        c++;
        if(c==pos-1)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nenter element to insert=");
            scanf("%d",&temp->data);
            temp->next=p->next;
            p->next=temp;
            break;
        }
        p=p->next;
    }
    return start;
}

struct node *del_beg(struct node *start)
{
    struct node *temp;
    temp=start;
    start=temp->next;
    free(temp);
    return start;
}

struct node *del_end(struct node *start)
{
    struct node *temp,*p;
    p=start;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    temp=p->next;
    p->next=temp->next;
    free(temp);
    return start;
}

struct node *del_item(struct node *start)
{
    struct node *temp,*p;
    if(start==NULL)
    {
        printf("\nlist is empty");
        return start;
    }
    int item;
    printf("\nenter item to delete=");
    scanf("%d",&item);
    if(start->data==item)
    {
        start=del_beg(start);
        return start;
    }
    p=start;
    while(p->next!=NULL)
    {
        if(p->next->data==item)
        {
            temp=p->next;
            p->next=temp->next;
            free(temp);
            return start;
        }
        p=p->next;
    }
    printf("\nelement not found");
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *ptr,*prev,*n;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        n=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=n;
    }
    start=prev;
    printf("\nlinked list reversed!");
    return start;
}

struct node *concat(struct node *s1,struct node *s2)
{
    struct node *p;
    p=s1;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=s2;
    return s1;
}

struct node *call_concat(struct node *start)
{
    int op1,i,n;
    struct node *start2=NULL;
    printf("\nselect:");
    printf("\n1.concatenate another list with current list");
    printf("\n2.concatenate current list with another list");
    printf("\n3.concatenate n lists with current list");
    scanf("%d",&op1);
    switch(op1)
    {
        case 1:
            printf("\ncreate another list");
            start2=create(start2);
            start=concat(start,start2);
            printf("\nconcatenated list:");
            display(start);
            break;

        case 2:
            printf("\ncreate another list");
            start2=create(start2);
            start2=concat(start2,start);
            printf("\nconcatenated list:");
            display(start2);
            break;

        case 3:
            printf("\nenter number of lists to create and join in current list=");
            scanf("%d",&n);
            for(i=2;i<=n+1;i++)
            {
                printf("\ncreate list %d",i);
                start2=create(start2);
                start=concat(start,start2);
                printf("\nconcatenated list:");
                getche();
                //display(start);
            }
            break;
    }
    return start;
}

struct node *my_ssort(struct node *start)
{
    struct node *p,*q,*r;
    int temp;
    p=start;
    while(p->next!=NULL)
    {
        r=p;
        q=p->next;
        while(q!=NULL)
        {
            if(q->data<r->data)
            {
                r=q;
            }
            q=q->next;
        }
        temp=r->data;
        r->data=p->data;
        p->data=temp;
        p=p->next;
    }
    return start;
}

struct node *my_bsort(struct node *start)
{
    struct node *p,*q;
    int temp,c,n=0,i=0;
    n=count(start);
    p=start;
    while(p->next!=NULL)
    {
        q=p;
        while(q!=NULL && n<c-i-1)
        {
            if(q->data<p->data)
            {
                temp=q->data;
                q->data=p->data;
                p->data=temp;
            }
            q=q->next;
        }
        p=p->next;
        i++;
        n++;
    }
    return start;
}

struct node *ssort(struct node *start)
{
    struct node *p,*q;
    int temp;
    p=start;
    while(p->next!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
    return start;
}

struct node *bsort(struct node *start)
{
    struct node *p,*q;
    int temp;
    p=NULL;
    while(p!=start->next)
    {
        q=start;
        while(q->next!=p)
        {
            if(q->next->data<q->data)
            {
                temp=q->data;
                q->data=q->next->data;
                q->next->data=temp;
            }
            q=q->next;
        }
        p=q;
    }
    return start;
}

void find_min(struct node *start)
{
    struct node *p;
    int min;
    p=start;
    min=p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(p->data<min)
        {
            min=p->data;
        }
        p=p->next;
    }
    printf("\nminimum value in list: %d",min);
}

void find_max(struct node *start)
{
    struct node *p;
    int max;
    p=start;
    max=p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    printf("\nmaximum value in list: %d",max);
}

struct node *my_merge(struct node *s1,struct node *s2)
{
    s1=concat(s1,s2);
    s1=bsort(s1);
    return s1;
}

struct node *merge(struct node *s1,struct node *s2)
{
    struct node *p,*q,*r,*t,*temp;
    p=s1;
    q=s2;
    r=NULL;
    if(p->data<q->data)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=p->data;
        temp->next=NULL;
        r=temp;
        p=p->next;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=q->data;
        temp->next=NULL;
        r=temp;
        q=q->next;
    }

    while(p->data<q->data && p!=NULL && q!=NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=p->data;
        temp->next=NULL;
        r->next=temp;
        p=p->next;
    }

    while(q->data<p->data && p!=NULL && q!=NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=q->data;
        temp->next=NULL;
        r->next=temp;
        q=q->next;
    }
    return r;
}

