#include<stdio.h>
#include<conio.h>
struct queue
{
    int capacity;
    int head,tail;
    int *ptr;
};
struct queue* createQueue(int cap)
{
 struct queue *q;
 q=(struct queue*)malloc(sizeof(struct queue));
 q->capacity=cap;
 q->head=-1;
 q->tail=-1;
 q->ptr=(int*)malloc(sizeof(int)*cap);
 return q;
}
void inserth(struct queue *q,int data)
{
    int i;
    if(q->head==0&&q->tail==q->capacity-1||q->head-1==q->tail)
        printf("overflow queue");
    else if(q->tail==-1)
        {
            q->head=0;
            q->tail=0;
            q->ptr[q->tail]=data;
        }
        else
        {
            for(i=q->tail;i!=q->head;)
            {
                if(i==q->capacity-1)
                    q->ptr[0]=q->ptr[i];
                else
                    q->ptr[i+1]=q->ptr[i];
                if(i==0)
                    i=q->capacity-1;
                else
                    i--;
            }
            q->ptr[i+1]=q->ptr[i];
            q->ptr[q->head]=data;
            if(q->tail==q->capacity-1)
                q->tail=0;
            else
                q->tail+=1;
        }
}
void insertt(struct queue *q,int data)
{
    if(q->head==0&&q->tail==q->capacity-1||q->head-1==q->tail)
        printf("overflow queue");
    else
    {
        if(q->tail==-1)
        {
            q->head=0;
            q->tail=0;
            q->ptr[q->tail]=data;
        }
        else if(q->tail==q->capacity-1)
        {
            q->tail=0;
            q->ptr[q->tail]=data;
        }
        else
        {
            q->tail+=1;
            q->ptr[q->tail]=data;
        }
    }
}
void deleteh(struct queue *q)
{
    if(q->tail==-1)
        printf("under flow queue");
    else if(q->tail==q->head)
    {
        q->head=-1;
        q->tail=-1;
    }
    else if(q->head==q->capacity-1)
        q->head=0;
    else
        q->head+=1;
}
void deletet(struct queue *q)
{
    if(q->tail==-1)
        printf("underflow queue");
    else if(q->tail==q->head)
    {
        q->head=-1;
        q->tail=-1;
    }
    else if(q->tail==0)
        q->tail=q->capacity-1;
    else
        q->tail-=1;
}
void viewh(struct queue *q)
{
    if(q->tail!=0)
        printf("%d",q->ptr[q->head]);
    else
        printf("empty queue");
}
void viewt(struct queue *q)
{
    if(q->tail!=0)
        printf("%d",q->ptr[q->tail]);
    else
        printf("empty queue");
}
main()
{
    struct queue *q;
    int choice,data;
    q=createQueue(5);
    while(1)
    {
        system("cls");
        printf("head=%d and tail=%d",q->head,q->tail);
        printf("\n1.for insert data to head");
        printf("\n2.for insert data to tail");
        printf("\n3.for delete data of head");
        printf("\n4.for delete data of tail");
        printf("\n5.for view data of head");
        printf("\n6.for view data of tail");
        printf("\n7.for exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to store:");
            scanf("%d",&data);
            inserth(q,data);
            break;
        case 2:
            printf("enter the data to store:");
            scanf("%d",&data);
            insertt(q,data);
            break;
        case 3:
            deleteh(q);
            break;
        case 4:
            deletet(q);
            break;
        case 5:
            viewh(q);
            break;
        case 6:
            viewt(q);
            break;
        case 7:
            printf("THANK YOU \nPRESS ANY TO EXIT..");
            getch();
            exit(0);
        default :
            printf("invalid choice");
        }
        getch();
    }
}
