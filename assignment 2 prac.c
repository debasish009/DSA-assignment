#include<stdio.h>
#include<conio.h>
struct Array
{
    int capacity;
    int lastIndex;
    int *ptr;
};
struct Array* createArray(int);
struct Array* createArray(int cap)
{
        struct Array book *arr;
    arr=(struct Array*)malloc(sizeof(struct Array));
    arr->capacity=cap;
    arr->lastIndex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*cap);
    return arr;
};
main()
{
    struct Array *arr;
    arr=createArray(5);
    getch();
}
