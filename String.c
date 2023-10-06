#include<stdio.h>
int main()
{
    char A[50];
    int i=0;
    int c=0;
    printf("Enter string\n");
    gets(A);
    while(A[i]!='\0')
    {
        if(A[i]=='y')
        {
            A[i]='a';
        }

       
        A[i]=A[i]+c;
        i++;
        c++;

        if(A[i] == ' ')
        {
            c=0;
        }
    }
    printf("%s",A);
    return 0;
}