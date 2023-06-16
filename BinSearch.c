#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10],i,index,data;
    printf("enter the number of array:");
    for(i=0;i<=9;i++)
        scanf("%d",&a[i]);
    printf("before sorted:");
    for(i=0;i<=9;i++)
        printf(" %d",a[i]);
    boublesort(a,10);
    printf("\nafter sorted:");
    for(i=0;i<=9;i++)
        printf(" %d",a[i]);
    printf("\nenter item to search:");
    scanf("%d",&data);
    index=BinSearch(a,10,data);
    if(index==-1)
        printf("not found");
    else
        printf("index is %d",index);
    getch();
}
int BinSearch(int a[],int size,int data)
{
    int l,u,m;
    l=0;
    u=size-1;
    while(l<=u)
    {
        m=(u+l)/2;
        if(a[m]==data)
            return m;
        else if(a[m]>data)
            u=m-1;
        else
            l=m+1;
    }
    return -1;
}
void boublesort(int a[],int size)
{
    int round,i,temp;
    for(round=1;round<=size-1;round++)
    {
        for(i=0;i<=size-1-round;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=a[i];
            }
        }
    }
}
