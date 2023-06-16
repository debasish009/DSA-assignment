#include<stdio.h>
#include<conio.h>
struct Array
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct Array* createArray(int cap)
{
    struct Array *arr;
    arr=(struct Array*)malloc(sizeof(struct Array));
    arr->capacity=cap;
    arr->lastindex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*cap);
    return arr;
}
void append(struct Array *arr,int data)
{
    if(arr->lastindex==arr->capacity-1)
        printf("overflow");
    else
    {
        arr->lastindex+=1;
        arr->ptr[arr->lastindex]=data;
    }
}
void insert(struct Array *arr,int index,int data)
{
    int i;
    if(index<0||index>arr->lastindex+1)
        printf("invalid index");
    else if(arr->lastindex==arr->capacity-1)
        printf("overflow");
    else
    {
        for(i=arr->lastindex;i>=index;i--)
            arr->ptr[i+1]=arr->ptr[i];
        arr->ptr[index]=data;
        arr->lastindex+=1;
    }
}
void edit(struct Array *arr,int index,int data)
{
    if(index<0||index>=arr->lastindex)
        printf("invalid index");
    else
        arr->ptr[index]=data;
}
void del(struct Array *arr,int index)
{
    int i;
    if(index<0||index>arr->lastindex)
        printf("invalid index");
    else
    {
        for(i=index;i<=arr->lastindex-1;i++)
            arr->ptr[i]=arr->ptr[i+1];
    }
    arr->lastindex-=1;
}
void view(struct Array *arr)
{
    int i;
    for(i=0;i<=arr->lastindex;i++)
        printf(" %d",arr->ptr[i]);
}
int count(struct Array *arr)
{
    int c;
    c=arr->lastindex+1;
    printf("total number in array is %d",c);
}
void search(struct Array *arr,int num)
{
  int i;
  for(i=0;i<=arr->lastindex;i++)
  {
      if(arr->ptr[i]==num)
        printf("index is %d",i);
  }
}
void item(struct Array *arr,int index)
{
    if(index<0||index>=arr->lastindex)
        printf("invalid index");
    else
        printf("item is %d",arr->ptr[index]);
}
main()
{
    int data,index,choice;
    struct Array *arr;
    arr=createArray(5);
    while(1)
    {
        system("cls");
        view(arr);
        printf("\n1. Append new element");
        printf("\n2. Insert new element");
        printf("\n3. Edit element");
        printf("\n4. Delete element");
        printf("\n5. Exit");
        printf("\nenter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to store:");
            scanf("%d",&data);
            append(arr,data);
            break;
        case 2:
            printf("enter the data to store:");
            scanf("%d",&data);
            printf("enter the index number(start from 0)of array:");
            scanf("%d",&index);
            insert(arr,index,data);
            break;
        case 3:
            printf("enter the data to store:");
            scanf("%d",&data);
            printf("enter the index number(start from 0)of array:");
            scanf("%d",&index);
            edit(arr,index,data);
            break;
        case 4:
            printf("enter the index number(start from 0)of array to delete:");
            scanf("%d",&index);
            del(arr,index);
            break;
        case 5:
            printf("Thank You\nPress any to exit");
            getch();
            exit(0);
        default:
            printf("Invalid choice");
        }
    getch();
    }
}
