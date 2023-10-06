#include<iostream>
using namespace std;

#define SIZE 8

bool BinarySerch(int *arr,int start,int end,int key)
{
    int mid=0;

    while(start<=end)
    {
        mid=(start+end)/2;

        if(arr[mid]==key)
        {
            return true;
        }

        if(arr[mid]<key)
        {
            start=mid+1;

        }
        else
        {
            end=mid-1;
        }
    }
    return false;

}


int main()
{
    int arr[SIZE]={10,23,55,70,90,100,111,123};
    int key=90;

    if(BinarySerch(arr,0,SIZE-1,key)==true)
    {
        cout<<"Found\n";

    }
    else
    {
        cout<<"Not found\n";
    }


    return 0;
}