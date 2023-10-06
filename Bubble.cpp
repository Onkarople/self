#include<iostream>

using namespace std;

void Bubble_sort(int arr[],int n)
{
    int temp=0;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(arr[j]>arr[j+1])
            {
               temp=arr[j+1];
               arr[j+1]=arr[j];
               arr[j]=temp;

            }
        }
    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Bubble_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }




    return 0;
}