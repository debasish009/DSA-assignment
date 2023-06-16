#include<stdio.h>
#include<conio.h>
struct node
{
    int capacity;
    int f[3],r[3];
    int *ptr[3];
};
struct node* createQueue(int cap)
{
 struct node *q;
 q=(struct queue*)malloc(sizeof(struct node));
 q->capacity=cap;
 for(int i=0;i<3;i++)
    q->f[i]=q->r[i]=-1;
 for(int i=0;i<3;i++)
    q->ptr[i]=(int*)malloc(sizeof(int)*cap);
 return q;
}
void insert(struct node *q,int data,int p)
{
    int j;
    if(p==3)
    {
        if(q->f[0]==0&&q->r[0]==q->capacity-1||q->r[0]+1==q->f[0])
            printf("overflow queue for priority 3");
        else if(q->r[0]==-1)
        {
            q->f[0]=0;
           j=q->r[0]=0;
            q->ptr[0][j]=data;
        }
        else if(q->r[0]==q->capacity-1)
        {
            j=q->r[0]=0;
            q->ptr[0][j]=data;
        }
        else
        {
            q->r[0]+=1;
            j=q->r[0];
            q->ptr[0][j]=data;
        }
    }
    else if(p==2)
    {
        if(q->f[1]==0&&q->r[1]==q->capacity-1||q->r[1]+1==q->f[1])
            printf("overflow queue for priority 2");
        else if(q->r[1]==-1)
        {
            q->f[1]=0;
            j=q->r[1]=0;
            q->ptr[1][j]=data;
        }
        else if(q->r[1]==q->capacity-1)
        {
            j=q->r[1]=0;
            q->ptr[1][j]=data;
        }
        else
        {
            q->r[1]+=1;
            j=q->r[1];
            q->ptr[1][j]=data;
        }
    }
    else if(p==1)
    {
        if(q->f[2]==0&&q->r[2]==q->capacity-1||q->r[2]+1==q->f[2])
            printf("overflow queue for priority 1");
        else if(q->r[2]==-1)
        {
            q->f[2]=0;
            j=q->r[2]=0;
            q->ptr[2][j]=data;
        }
        else if(q->r[2]==q->capacity-1)
        {
            j=q->r[2]=0;
            q->ptr[2][j]=data;
        }
        else
        {
            q->r[2]+=1;
            j=q->r[2];
            q->ptr[2][j]=data;
        }
    }
    else
        printf("enter valid priority number 1 or 2 or 3");
}
void deletion(struct node *q)
{
    if(q->r[0]!=-1)
    {
        if(q->f[0]==q->r[0])
        {
            q->f[0]=-1;
            q->r[0]=-1;
        }
        else if(q->f[0]==q->capacity-1)
            q->f[0]=0;
        else
            q->f[0]+=1;
    }
    else if(q->r[0]==-1&&q->r[1]!=-1)
    {
      if(q->f[1]==q->r[1])
        {
            q->f[1]=-1;
            q->r[1]=-1;
        }
        else if(q->f[1]==q->capacity-1)
            q->f[1]=0;
        else
            q->f[1]+=1;
    }
    else if(q->r[0]==-1&&q->r[1]==-1&&q->r[2]!=-1)
    {
        if(q->f[2]==q->r[2])
        {
            q->f[2]=-1;
            q->r[2]=-1;
        }
        else if(q->f[2]==q->capacity-1)
            q->f[2]=0;
        else
            q->f[2]+=1;
    }
}
void view(struct node *q)
{
    if(q->r[0]!=-1)
        printf("%d",q->f[0]);
    else if(q->r[0]==-1&&q->r[1]!=-1)
        printf("%d",q->f[1]);
    else if(q->r[0]==-1&&q->r[1]==-1&&q->r[2]!=-1)
        printf("%d",q->f[2]);
}
main()
{
    struct node *q;
    int data,choice,p;
    q=createQueue(5);
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
            printf("give the priority no(1/2/3):");
            scanf("%d",&p);
            insert(q,data,p);
            break;
        case 2:
            deletion(q);
            break;
        case 3:
            view(q);
            break;
        case 4:
            printf("THANK YOU\nPRESS ANY TO EXIT..");
            getch();
            exit(0);
        default :
            printf("invalid choice");
        }
        getch();
    }
}
