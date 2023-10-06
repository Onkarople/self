#include<stdio.h>

void Display(int *ptr)
{
    printf("Elements are:-");

    for(int i=0;i<5;i++)
    {
        printf("%d",ptr[i]);
    }
}



int main()
{
    int Arr[5];
    printf("Enter Elements\n");

    for(int i=0;i<5;i++)
    {
        scanf("%d\n",&Arr[i]);

    }

    Display(Arr);




    return 0;
}