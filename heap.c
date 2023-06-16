#include<stdio.h>
#include<conio.h>
void main()
{
    int i,a[10]={100,22,55,11,77,44,33,99,88,66};
    heapSort(a,10);
    for(i=0;i<=9;i++)
        printf(" %d",a[i]);
    getch();
}
void heapSort(int a[],int n)
{
    int j,item;
    for(j=0;j<n-1;j++)
        insert(a,j,a[j+1]);
    while(n>0)
    {
        del(a,n-1,&item);
        a[n-1]=item;
        n--;
    }
}
void insert(int a[],int n,int value)
{
    int index,parindex;
    n++;
    index=n;
    while(index>0)
    {
        parindex=(index-1)/2;
        if(value<=a[parindex])
            break;
        a[index]=a[parindex];
        index=parindex;
    }
    a[index]=value;
}
void del(int a[],int n,int *v)
{
    int last,index,left,right;
    *v=a[0];
    last=a[n];
    n--;
    index=0;
    left=1;
    right=2;
    while(right<=n)
    {
        if(last>=a[left]&&last>=a[right])
        {
            a[index]=last;
            return;
        }
        if(a[left]>=a[right])
        {
            a[index]=a[left];
            index=left;
        }
        else
        {
            a[index]=a[right];
            index=right;
        }
        left=2*index+1;
        right=2*index+2;
    }
    if(left==n&&last<a[left])
    {
        a[index]=a[left];
        index=left;
    }
    a[index]=last;
}
