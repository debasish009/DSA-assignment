#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10],i,data,index;
    printf("enter the number of array:");
    for(i=0;i<=9;i++)
        scanf("%d",&a[i]);
    printf("enter the item to search:");
    scanf("%d",&data);
    index=LinSearch(a,10,data);
    printf("index is %d",index);
    getch();
}
int LinSearch(int a[],int size,int data)
{
    int i;
    for(i=0;i<=size-1;i++)
    {
        if(a[i]==data)
            return i;
    }
    return -1;
}
