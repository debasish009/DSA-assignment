#include<stdio.h>
#include<conio.h>
void main()
{
    char str[]="ABC";
    permutation(str,0,strlen(str)-1);
    getch();
}
void permutation(char s[],int i,int j)
    {
        char ch;
        int x;
        if(i==j)
            printf("%s\n",s);
        else
        {
            for(x=i;x<=j;x++)
            {
                ch=s[i];
                s[i]=s[x];
                s[x]=ch;
                permutation(s,i+1,j);
                ch=s[i];
                s[i]=s[x];
                s[x]=ch;
            }
        }
    }


