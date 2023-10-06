#include<iostream>
using namespace std;

#define SIZE 5


bool LinearSerch(int *arr,int size,int key)
{
    int i;

    for(i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return true;
        }
    }

    return false;

}

int main()
{
   int arr[SIZE]={10,23,5,60,89};

   int key=5;

   if(LinearSerch(arr,SIZE,key)==true)
   {
     cout<<"Found\n";
   }
   else
   {
    cout<<"not found\n";
   }

    return 0;
}