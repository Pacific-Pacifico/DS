#include "s_list.h"
int main()
{
struct node *start=NULL;
int ch,data,item,pos;
while(1)
{
    printf("\n\n1.create list\n");
    printf("2.display\n");
    printf("3.count\n");
    printf("4.search\n");
    printf("5.insert in empty list/add at beginning\n");
    printf("6.add at end\n");
    printf("7.add after node\n");
    printf("8.add before node\n");
    printf("9.add at position\n");
    printf("10.delete\n");
    printf("11.reverse\n");
    printf("12.quit\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            start=create_list(start);
            break;

        case 2:
            display(start);
            break;

        case 3:
            count(start);
            break;

        case 4:
            printf("enter item to search=");
            scanf("%d",&item);
            search(start,item);
            break;

        case 5:
            printf("enter data to insert=");
            scanf("%d",&data);
            start=ins_beg(start,data);
            break;

        case 6:
            printf("enter data to insert=");
            scanf("%d",&data);
            start=ins_end(start,data);
            break;

        case 7:
            printf("enter data to insert=");
            scanf("%d",&data);
            start=ins_after(start,data);
            break;

        case 8:
            printf("enter data to insert=");
            scanf("%d",&data);
            start=ins_before(start,data);
            break;

        case 9:
            printf("enter data to insert=");
            scanf("%d",&data);
            printf("enter position");
            scanf("%d",&pos);
            start=ins_pos(start,data,pos);
            break;

        case 10:
            printf("enter position of data to be deleted=");
            scanf("%d",&pos);
            start=del_pos(start,pos);
            break;

        case 11:
            start=reverse(start);
            break;

        case 12:
            exit(1);

        default:
            printf("wrong choice\n");
    }
}
}



