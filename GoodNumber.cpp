#include<iostream>
using namespace std;


bool IsGoodNumber(int iNo)
{
    int iDigit=0;
    int iTemp=iNo;

    if(iNo<0)
    {
        cout<<"Enter positive number";
        return false;
    }
    
    if(iNo==7)
    {
        return false;
    }

    while(iNo!=0)
    {
        iDigit=iNo%10;
        if(iDigit==7)
        {
            return false;
            break;
        }
        iNo=iNo/10;
    }

    iNo=iTemp;

    if((iNo%7)==0)
    {
        return true;
    }
   
   return false;

}


int main()
{
    int iNo=0;
    bool iRet=false;

    cout<<"Enter A Number\n";
    cin>>iNo;

    iRet=IsGoodNumber(iNo);

    if(iRet==true)
    {
        cout<<"True";
    }
    else
    {
        cout<<"false";
    }


    return 0;


}
