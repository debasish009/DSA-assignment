#include<stdio.h>
#include<conio.h>
struct stack
{
    int capacity;
    int top1,top2;
    int *ptr;
};
struct stack* crearteStack(int cap)
{
 struct stack *s;
 s=(struct stack*)malloc(sizeof(struct stack));
 s->capacity=cap;
 s->top1=-1;
 s->top2=cap;
 s->ptr=(int*)malloc(sizeof(int)*cap);
 return s;
}
void pushStack1(struct stack *s,int data)
{
    if(s->top1==s->top2-1)
        printf("stack is over flow");
    else
    {
        s->top1+=1;
        s->ptr[s->top1]=data;
    }
}
void pushStack2(struct stack *s,int data)
{
    if(s->top1==s->top2-1)
        printf("stack is over flow");
    else
    {
        s->top2-=1;
        s->ptr[s->top2]=data;
    }
}
void popStack1(struct stack *s)
{
    if(s->top1==-1)
        printf("underflow stack1");
    else
        s->top1-=1;
}
void popStack2(struct stack *s)
{
    if(s->top2==s->capacity)
        printf("underflow stack2");
    else
        s->top2+=1;
}
void view(struct stack *s)
{
    int num;
    printf("which stack you want  to print (1.for stack1 2.for stack2):");
    scanf("%d",&num);
    if(num==1)
        printf("%d",s->ptr[s->top1]);
    else if(num==2)
        printf("%d",s->ptr[s->top2]);
    else
        printf("enter the valid stack number");
}
main()
{
    struct stack *s;
    int data,choice;
    s=crearteStack(5);
    while(1)
    {
        system("cls");
        printf("\n1.for push in stack1");
        printf("\n2.for push in stack2");
        printf("\n3.for pop in stack1");
        printf("\n4.for pop in stack2");
        printf("\n5.for view");
        printf("\n6.for exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to store in stack1:");
            scanf("%d",&data);
            pushStack1(s,data);
            break;
        case 2:
            printf("enter the data to store in stack2:");
            scanf("%d",&data);
            pushStack2(s,data);
            break;
        case 3:
            popStack1(s);
            break;
        case 4:
            popStack2(s);
            break;
        case 5:
            view(s);
            break;
        case 6:
            printf("THANK YOU \nPRESS ANY TO EXIT..");
            getch();
            exit(0);
        default :
            printf("enter the valid choice");
        }
        getch();
    }
}

