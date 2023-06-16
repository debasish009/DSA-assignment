#include<stdio.h>
#include<conio.h>
struct node
{
    struct node *left;
    int item;
    struct node *right;
};
void insert(struct node **r,int data)
{
    struct node *n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(*r==NULL)
        *r=n;
    else
    {
        t=*r;
        while(1)
        {
            if(t->item==data)
            {
                free(n);
                break;
            }
            else if(t->item>data)
            {
                if(t->left==NULL)
                {
                    t->left=n;
                    break;
                }
                else
                    t=t->left;
            }
            else
            {
                if(t->right==NULL)
                {
                    t->right=n;
                    break;
                }
                else
                    t=t->right;
            }
        }
    }
}
void inorder(struct node *r)
{
    if(r){
    inorder(r->left);
    printf(" %d",r->item);
    inorder(r->right);}
}
void preorder(struct node *r)
{
    if(r)
    {
    printf(" %d",r->item);
    preorder(r->left);
    preorder(r->right);
    }
}
void postorder(struct node *r)
{
    if(r)
    {
        postorder(r->left);
        postorder(r->right);
        printf(" %d",r->item);
    }
}
void del(struct node **r,int data)
{
    struct node *ptr,*parptr,*suc,*parsuc;
    parptr=NULL;
    ptr=*r;
    //traversing
    while(ptr)
    {
        if(ptr->item==data)
            break;
        else if(ptr->item>data)
        {
            parptr=ptr;
            ptr=ptr->left;
        }
        else
        {
            parptr=ptr;
            ptr=ptr->right;
        }
    }
    //delete root node
    if(ptr!=NULL&&parptr==NULL)
    {
        if(ptr->left==NULL&&ptr->right==NULL)//no children
        {
            *r=NULL;
            free(ptr);
        }
        if(ptr->left==NULL || ptr->right==NULL)//1 chidren
        {
            if(ptr->left!=NULL)
                *r=ptr->left;
            else
                *r=ptr->right;
            free(ptr);
        }
        else //2 children
        {
            parsuc=ptr;
            suc=ptr->right;
            while(suc->left)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            if(suc->right==NULL)//0 child
            {
                if(parsuc->left==suc)
                    parsuc->left=NULL;
                else
                    parsuc->right=NULL;
                free(suc);
            }
            else //1 child
            {
                if(parsuc->left==suc)
                    parsuc->left=suc->right;
                else
                    parsuc->right=suc->right;
                free(suc);
            }
        }
    }
    else if(ptr!=NULL)
    {
        if(ptr->left==NULL&&ptr->right==NULL)//0 child
        {
           if(parptr->left==ptr)
              parptr->left=NULL;
           else
              parptr->right=NULL;
           free(ptr);
        }
        else if(ptr->left==NULL||ptr->right==NULL)//1 child
        {
            if(parptr->left==ptr)
            {
                if(ptr->left!=NULL)
                    parptr->left=ptr->left;
                else
                    parptr->left=ptr->right;
            }
            else
            {
                if(ptr->left!=NULL)
                    parptr->right=ptr->left;
                else
                    parptr->right=ptr->right;
            }
            free(ptr);
        }
        else//2 child
        {
            parsuc=ptr;
            suc=ptr->right;
            while(suc->left)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            //del suc
            if(suc->right==NULL)//0 child
            {
                if(parsuc->left==suc)
                    parsuc->left=NULL;
                else
                    parsuc->right=NULL;
                free(suc);
            }
            else//1 child
            {
                if(parsuc->left==suc)
                    parsuc->left=suc->right;
                else
                    parsuc->right=suc->right;
                free(suc);
            }
        }
    }
}
void main()
{
    struct node *root=NULL;
    int data,choice;
    while(1)
    {
        system("cls");
        printf("\n1.for insert");
        printf("\n2.for traversing");
        printf("\n3.for delete");
        printf("\n4.for exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to store:");
            scanf("%d",&data);
            insert(&root,data);
            break;
        case 2:
            printf("inorder traversing:");
            inorder(root);
            printf("\npreorder traversing:");
            preorder(root);
            printf("\npostorder traversing:");
            postorder(root);
            getch();
            break;
        case 3:
            printf("enter the data that you want to delete:");
            scanf("%d",&data);
            del(&root,data);
            break;
        case 4:
            exit(0);
        default :
            printf("invalid choice");
            getch();
        }
    }
}
