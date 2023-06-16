#include<stdio.h>
#include<conio.h>
struct node
{
    int item;
    struct node *next;
};
void insertAtfirst(struct node **s,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=*s;
    *s=n;
}
void insertAtlast(struct node **s,int data)
{
    struct node *n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
        *s=n;
    else
       {
        t=*s;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
       }
}
void delFirst(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("\n empty list");
    else
    {
        t=*s;
        *s=t->next;
        free(t);
    }
}
void delAtlast(struct node **s)
{
    struct node *t1,*t2;
    if(*s==NULL)
        printf("\n empty list");
    else
    {
        t1=*s;
        t2=NULL;
        while(t1->next!=NULL)
        {
            t2=t1;
            t1=t1->next;
        }
        free(t1);
        if(t2==NULL)
            *s=NULL;
        else
            t2->next=NULL;
    }
}
void insertAfter(struct node *t,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=t->next;
    t->next=n;
}
struct node* search(struct node *start,int data)
{
 while(start)
 {
     if(start->item==data)
        return start;
     start=start->next;
 }
 return NULL;
}
void delnode(struct node **s,struct node *t)
{
    struct node *r;
    r=*s;
    if(r==t)
    {
      *s=r->next;
      free(t);
    }
    else
    {
        while(r->next!=t)
            r=r->next;
        r->next=t->next;
        free(t);
    }
}
void view(struct node *start)
{
    while(start)
    {
        printf("%d ",start->item);
        start=start->next;
    }
}
main()
{
    struct node *t,*start=NULL;
    int data1,data2,item,choice;
    while(1)
    {
        system("cls");
        view(start);
        printf("\n1.for insert at first");
        printf("\n2.for insert at last");
        printf("\n3.for delete first");
        printf("\n4.for delete at last");
        printf("\n5.for insert after");
        printf("\n6.for delete node");
        printf("\n7.for exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter data to store in first:");
            scanf("%d",&data1);
            insertAtfirst(&start,data1);
            break;
        case 2:
            printf("enter the data to store in last:");
            scanf("%d",&data1);
            insertAtlast(&start,data1);
            break;
        case 3:
            delFirst(&start);
            break;
        case 4:
            delAtlast(&start);
            break;
        case 5:
            printf("enter the data after that new data store:");
            scanf("%d",&data1);
            t=search(start,data1);
            printf("enter new data to store:");
            scanf("%d",&data2);
            insertAfter(t,data2);
            break;
        case 6:
            printf("enter data that would be delete:");
            scanf("%d",&data1);
            t=search(start,data1);
            delnode(&start,t);
            break;
        case 7:
            printf("Thank You\nPress any to exit...");
            getch();
            exit(0);
        default :
            printf("invalid choice");
        }
        getch();
    }
}
