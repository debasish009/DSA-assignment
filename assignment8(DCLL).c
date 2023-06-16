#include<stdio.h>
#include<conio.h>
struct node
{
    struct node *prev;
    int item;
    struct node *next;
};
void insertFirst(struct node **s,int data)
{
    struct node *n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(*s==NULL)
    {
        n->prev=n;
        n->next=n;
        *s=n;
    }
    else
    {
        t=*s;
        n->prev=(*s)->prev;
        n->next=*s;
        (*s)->prev=n;
        while(t->next!=*s)
            t=t->next;
        t->next=n;
        *s=n;
    }
}
void insertLast(struct node **s,int data)
{
    struct node *n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(*s==NULL)
    {
        n->prev=n;
        n->next=n;
        *s=n;
    }
    else
    {
        t=*s;
        while(t->next!=*s)
            t=t->next;
        n->prev=t;
        n->next=t->next;
        t->next=n;
    }
}
void deleteFirst(struct node **s)
{
    struct node *t,*r;
    if(*s==NULL)
        printf("empty list");
    else
    {
        t=*s;
        *s=t->next;
        if(t->next==t)
            *s==NULL;
        else
        {
            r=*s;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            (*s)->prev=t->prev;
        }
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
        while(t->next!=*s)
            t=t->next;
        if(t->prev!=t)
        {
            t->prev->next=t->next;
            (*s)->prev=t->prev;
        }
        else
            *s=NULL;
        free(t);
    }
}
void insertAfter(struct node *t,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->prev=t;
    n->next=t->next;
    t->next=n;
}
void deleteNode(struct node **s,struct node *t)
{
    if(*s==NULL)
        printf("empty list");
    else
        {
            t->prev->next=t->next;
            t->next->prev=t->prev;
            if(t=*s&&t->next==t)
                *s=NULL;
            if(t==*s)
                *s=t->next;
            free(t);
        }
}
struct node* search(struct node *start,int data)
{
 struct node *r;
 r=start;
 if(start==NULL)
        return NULL;
 else
 {
     do
     {
        if(r->item==data)
            return r;
        r=r->next;
     }while(r!=start);
     return NULL;
 }
}
void view(struct node *start)
{
    struct node *r;
    r=start;
    if(start==NULL)
        printf("empty list");
    else{
    do
    {
        printf("%d ",r->item);
        r=r->next;
    }while(r!=start);
    }
}
main()
{
    struct node *start=NULL,*t;
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
        printf("\n7.for view");
        printf("\n8.for exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to store in first:");
            scanf("%d",&data);
            insertFirst(&start,data);
            break;
        case 2:
            printf("enter the data to store in last:");
            scanf("%d",&data);
            insertLast(&start,data);
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
            printf("enter new data to store");
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
            view(start);
            break;
        case 8:
            printf("THANK YOU \nPRESS ANY TO EXIT...");
            getch();
            exit(0);
        default :
            printf("invalid choice");
        }
        getch();
    }

}
