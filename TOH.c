#include<stdio.h>
#include<conio.h>
void main()
{
    int n;
    printf("enter the disc number:");
    scanf("%d",&n);
    TOH(n,'A','B','C');
    getch();
}
void TOH(int n,char BEG,char AUX,char END)
{
    static int c;
    if(n>0)
    {
        TOH(n-1,BEG,END,AUX);
        printf("\n%d.%C->%C",++c,BEG,END);
        TOH(n-1,AUX,BEG,END);
    }
}
