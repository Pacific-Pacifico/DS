#include<stdio.h>
#define ROW 3
#define COL 3

#define S_ROW 3

void display(int[][COL],int,int);
int count_size(int[][COL],int,int);

int main()
{
int i,j,a[ROW][COL],c;
for(i=0;i<ROW;i++)
{
    for(j=0;j<COL;j++)
    {
        printf("\na[%d][%d] : ",i,j);
        scanf("%d",&a[i][j]);
    }
}
display(a,ROW,COL);
c=count_size(a,ROW,COL);
printf("\nNumber of nonzero elements=%d",c);
int b[S_ROW][c],k=0;
for(i=0;i<ROW;i++)
{
    for(j=0;j<COL;j++)
    {
        if(a[i][j]!=0)
        {
            b[0][k]=i;
            b[1][k]=j;
            b[2][k]=a[i][j];
            k++;
        }
    }
}
printf("\n");
for(i=0;i<S_ROW;i++)
{
    for(j=0;j<c;j++)
    {
        printf("%d ",b[i][j]);
    }
    printf("\n");
}
//error in display()
//display(b,S_ROW,c);
}

void display(int a[][COL],int r,int c)
{
    int i,j;
    printf("\nArray:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int count_size(int a[][COL],int r,int c)
{
    int i,j,count=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                count++;
            }
        }
    }
    return count;
}

