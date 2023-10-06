#include<iostream>
using namespace std;

void Strrevx(char *str)
{
    char *start = str;
    char *end = str;
    char temp;

    while(*end!='\0')
    {
        end++;
    }
    end--;

    while(start<end)
    {
        temp=*start;
        *start=*end;
        *end=temp;

        start++;
        end--;
    }
}


int main()
{
    char Arr[20];
    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);

    Strrevx(Arr);

    cout<<Arr;


    return 0;


}