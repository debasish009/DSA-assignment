#include<stdio.h>
#include<conio.h>
struct dynArray
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct dynArray* createArray(int cap)
{
    struct dynArray *arr;
    arr=(struct dynArray*)malloc(sizeof(struct dynArray));
    arr->capacity=cap;
    arr->lastindex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*arr->capacity);
    return arr;
}
void append(struct dynArray *arr,int data)
{
    if(arr->lastindex==arr->capacity-1)
        doubleArray(arr);
    arr->lastindex+=1;
    arr->ptr[arr->lastindex]=data;
}
void insert(struct dynArray *arr,int index,int data)
{
    int i;
    if(index<0||index>arr->lastindex+1)
        printf("invalid index");
    else
    {
        if(arr->lastindex==arr->capacity-1)
            doubleArray(arr);
        for(i=arr->lastindex;i>=index;i--)
            arr->ptr[i+1]=arr->ptr[i];
        arr->ptr[index]=data;
        arr->lastindex+=1;
    }
}
void del(struct dynArray *arr,int index)
{
    int i;
    if(index<0||index>arr->lastindex)
        printf("invalid index or empty array");
    else
    {
      for(i=index;i<=arr->lastindex-1;i++)
          arr->ptr[i]=arr->ptr[i+1];
      arr->lastindex-=1;
      if(arr->lastindex+1<=arr->capacity/2)
        halfArray(arr);
    }
}
void countArray(struct dynArray *arr)
{
    int c;
    c=arr->lastindex+1;
    printf("total numbers in given array is %d",c);
}
void get(struct dynArray *arr,int index)
{
    if(index<0||index>arr->lastindex)
        printf("invalid index");
    else
        printf("number in given index is %d",arr->ptr[index]);
}
void edit(struct dynArray *arr,int index,int data)
{
    if(index<0||index>arr->lastindex)
        printf("invalid index");
    else
        arr->ptr[index]=data;
}
void search(struct dynArray *arr,int data)
{
    int i;
    for(i=0;i<=arr->lastindex;i++)
        if(arr->ptr[i]==data)
          break;
    printf("index is %d",i);
}
void doubleArray(struct dynArray *arr)
{
    int i,*temp;
    temp=(int*)malloc(sizeof(int)*arr->capacity*2);
    for(i=0;i<=arr->lastindex;i++)
        temp[i]=arr->ptr[i];
    free(arr->ptr);
    arr->ptr=temp;
    arr->capacity*=2;
}
void halfArray(struct dynArray *arr)
{
    int i,*temp;
    if(arr->capacity>1)
    {
    temp=(int*)malloc(sizeof(int)*arr->capacity/2);
    for(i=0;i<=arr->lastindex;i++)
        temp[i]=arr->ptr[i];
    free(arr->ptr);
    arr->ptr=temp;
    arr->capacity/=2;
    }
}
void view(struct dynArray *arr)
{
    int i;
    for(i=0;i<=arr->lastindex;i++)
        printf(" %d",arr->ptr[i]);
}
main()
{
    int choice,data,index;
    struct dynArray *arr;
    arr=createArray(5);
    while(1)
    {
        system("cls");
        view(arr);
        printf("\nno.1 for append");
        printf("\nno.2 for insert");
        printf("\nno.3 for delete");
        printf("\nno.4 for edit");
        printf("\nno.5 for exit");
        printf("\nselect your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter data to store in array:");
            scanf("%d",&data);
            append(arr,data);
            break;
        case 2:
            printf("enter data to store in array:");
            scanf("%d",&data);
            printf("enter index no (start from 0)of array:");
            scanf("%d",&index);
            insert(arr,index,data);
            break;
        case 3:
            printf("enter index no (start from 0)of array to delete:");
            scanf("%d",&index);
            del(arr,index);
            break;
        case 4:
            printf("enter data to store in array:");
            scanf("%d",&data);
            printf("enter index no (start from 0)of array:");
            scanf("%d",&index);
            edit(arr,index,data);
            break;
        case 5:
            printf("Thank You\nPress any to exit....");
            getch();
            exit(0);
        default:
            printf("invalid choice");
       }
    getch();
   }
}
