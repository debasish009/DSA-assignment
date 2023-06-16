#include<stdio.h>
#include<conio.h>
struct node
{
    int item;
    struct node *next;
};
void insertAtfirst(struct node **l,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(*l==NULL)
    {
      n->next=n;
      *l=n;
    }
     else
     {
      n->next=(*l)->next;
      (*l)->next=n;
     }
}
void insertAtlast(struct node **l,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(*l==NULL)
    {
        n->next=n;
        *l=n;
    }
    else
    {
        n->next=(*l)->next;
        (*l)->next=n;
        *l=n;
    }
}
void deleteFirst(struct node **l)
{
    struct node *t;
    if(*l==NULL)
        printf("empty list");
    else
    {
        t=(*l)->next;
        (*l)->next=t->next;
        if(*l==(*l)->next)
            *l=NULL;
        free(t);
    }
}
void deleteLast(struct node **l)
{
    struct node *t;
    if(*l==NULL)
        printf("empty list");
    else
    {
        t=(*l)->next;
        while(t->next!=*l)
            t=t->next;
        t->next=(*l)->next;
        if(*l==(*l)->next)
        {
            free(*l);
            *l=NULL;
        }
        else
        {
        free(*l);
        *l=t;
        }
    }
}
void insertAfter(struct node **l,struct node *t,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=t->next;
    t->next=n;
    if(*l==t)
        *l=n;
}
void deleteNode(struct node **l,struct node *t)
{
    struct node *r;
    if(*l==NULL)
        printf("empty list");
    else
    {
        if(*l==(*l)->next&&t==*l)
        {
          free(*l);
          *l=NULL;
        }
        else
        {
        r=(*l)->next;
        while(r->next!=t)
            r=r->next;
        r->next=t->next;
        if(*l==t)
            *l=r;
        free(t);
        }
    }
}
struct node* search(struct node *last,int data)
{
 struct node *t;
 t=last;
 if(last==NULL)
    return NULL;
 else
 {
 do
 {
    if(t->item==data)
        return t;
    t=t->next;
 }while(t!=last);
 return NULL;
 }
}
void view(struct node *last)
{
    struct node *s;
    s=last->next;
    do
    {
        printf("%d ",s->item);
        s=s->next;
    }while(s!=last->next);
}
main()
{
    struct node *last=NULL,*t;
    int choice,data,data1;
    while(1)
    {
        system("cls");
        printf("\n1.for insert at first");
        printf("\n2.for insert at last");
        printf("\n3.for delete at first");
        printf("\n4.for delete at last");
        printf("\n5.for insert after");
        printf("\n6.for delete node");
        printf("\n7.for exit");
        printf("\n8.for view");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to store in first:");
            scanf("%d",&data);
            insertAtfirst(&last,data);
            break;
        case 2:
            printf("enter the data to store in last:");
            scanf("%d",&data);
            insertAtlast(&last,data);
            break;
        case 3:
            deleteFirst(&last);
            break;
        case 4:
            deleteLast(&last);
            break;
        case 5:
            printf("enter the data after that new data store:");
            scanf("%d",&data);
            t=search(last,data);
            printf("enter new data to store:");
            scanf("%d",&data1);
            insertAfter(&last,t,data1);
            break;
        case 6:
            printf("enter the data that would be delete:");
            scanf("%d",&data);
            t=search(last,data);
            deleteNode(&last,t);
            break;
        case 7:
            printf("Thank You\nPress any key to exit");
            getch();
            exit(0);
        case 8:
            view(last);
            break;
        default :
            printf("invalid choice");
        }
        getch();
    }

}

