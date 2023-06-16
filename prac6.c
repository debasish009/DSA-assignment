
#include<stdio.h>
#include<conio.h>
struct node
{
    struct node *prev;
    int item;
    struct node *next;
};
void insertAtfirst(struct node **s,int data)
{
 struct node *n;
 n=(struct node*)malloc(sizeof(struct node));
 n->item=data;
 n->prev=NULL;
 n->next=*s;
 if(*s!=NULL)
    (*s)->prev=n;
 *s=n;
}
void insertAtlast(struct node **s,int data)
{
    struct node *n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=NULL;
    t=*s;
    if(*s==NULL)
    {
        n->prev=NULL;
        *s=n;
    }
    else
    {
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }
}
void deleteFirst(struct node **s)
{
  struct node *t;
  if(*s==NULL)
        printf("empty list");
  else
  {
      t=*s;
      *s=t->next;
      if(*s!=NULL)
        (*s)->prev=NULL;
      free(t);
  }
}
void deleteLast(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("empty list");
    else
    {
        t=*s;
            while(t->next!=NULL)
                t=t->next;
            if(t->prev!=NULL)
                t->prev->next=NULL;
            else
              *s=t->next;
            free(t);
    }
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
void insertAfter(struct node *t,int data)
{
  struct node *n;
  n=(struct node*)malloc(sizeof(struct node));
  n->item=data;
  n->next=t->next;
  n->prev=t;
  if(t->next!=NULL)
    t->next->prev=n;
  t->next=n;
}
void deleteNode(struct node **s,struct node *t)
{
    if(t->next!=NULL)
        t->next->prev=t->prev;
    if(t->prev!=NULL)
        t->prev->next=t->next;
    else
        *s=t->next;
    free(t);
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
    struct node *t;
    struct node *start=NULL;
    int choice,data,data1;
    while(1)
    {
        system("cls");
        view(start);
        printf("\n1.for insert at first");
        printf("\n2.for insert at last");
        printf("\n3.for delete first");
        printf("\n4.for delete last");
        printf("\n5.for insert After");
        printf("\n6.for delete node");
        printf("\n7.for exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter data to store in first:");
            scanf("%d",&data);
            insertAtfirst(&start,data);
            break;
        case 2:
            printf("enter the data to store in last:");
            scanf("%d",&data);
            insertAtlast(&start,data);
            break;
        case 3:
            deleteFirst(&start);
            break;
        case 4:
            deleteLast(&start);
            break;
        case 5:
            printf("enter the data after that new data store:");
            scanf("%d",&data);
            t=search(start,data);
            printf("enter new data to store:");
            scanf("%d",&data1);
            insertAfter(t,data1);
            break;
        case 6:
            printf("enter the data that would be delete:");
            scanf("%d",&data);
            t=search(start,data);
            deleteNode(&start,t);
            break;
        case 7:
            printf("Thank You\nPress any key to exit....");
            getch();
            exit(0);
        default :
            printf("invalid choice");
        }
        getch();
    }
}
