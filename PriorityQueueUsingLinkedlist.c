#include<stdio.h>
#include<conio.h>
struct node
{
    int priority;
    int item;
    struct node *next;
};
void push(struct node **s,int data,int p)
{
    struct node *n,*t=NULL,*t1=NULL;
    int c=0;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->priority=p;
    if(*s==NULL)
    {
        n->next=NULL;
        *s=n;
    }
    else
    {
        if(n->priority > (*s)->priority)
        {
        n->next=*s;
        *s=n;
        }
        else
       {
        t=*s;
        t1=*s;
        while(t->priority>=n->priority)
         {
            if(t->next==NULL)
            {
                n->next=NULL;
                t->next=n;
                c=1;
                break;
            }
            else
                t=t->next;
         }
          if(c!=1)
          {
            while(t1->next!=t)
                t1=t1->next;
          n->next=t1->next;
          t1->next=n;
          }
        }
      }
    }

void pop(struct node **s)
{
    if(*s==NULL)
        printf("Queue is underflow");
    else
    {
     struct node *t;
     t=*s;
     *s=t->next;
     free(t);
    }
}
void view(struct node *s)
{
    struct node *t;
    t=s;
    if(t!=NULL)
    {
       while(t->next!=NULL)
        {
            printf("\npriority=%d,item=%d",t->priority,t->item);
             t=t->next;
        }
         printf("\npriority=%d,item=%d",t->priority,t->item);
    }
    else
        printf("empty queue");
}
main()
{
    struct node *s=NULL;
    int data,p,choice;
    while(1)
    {
        system("cls");
        printf("1.for insertion");
        printf("\n2.for deletion");
        printf("\n3.for view");
        printf("\n4.for exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to store:");
            scanf("%d",&data);
            printf("enter the priority:");
            scanf("%d",&p);
            push(&s,data,p);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            view(s);
            break;
        case 4:
            printf("THANK YOU \nPRESS ANY TO EXIT..");
            getch();
            exit(0);
        default :
            printf("invalid choice");
        }
        getch();
    }
}
