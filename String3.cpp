#include<iostream>
using namespace std;

int Strlwrx(char *str)
{
    int iCnt=0;
    while(*str!='\0')
    {
        if(*str>='A'&& *str<='Z')
        {
            *str=*str+32;
        }

        str++;

    }

    return iCnt;
}

int main()
{
    char Arr[20];
    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);


    Strlwrx(Arr);

    cout<<"Lower case is :"<<Arr<<endl;


    return 0;


}