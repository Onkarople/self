#include<stdio.h>
#include<stdlib.h>

int main()
{
    
    int a=10;

    char c = 'a';
    float b=0.0;
    double d=0.0;

    int Arr[]={1,2,3,5,6};
    printf("%d",Arr[0]);

    int *ptr=NULL;
    ptr=(int *)malloc(5*sizeof(int));

    if(ptr==0)
    {
        printf("NO");
    }
    else
    {
        printf("yes");
    }



}