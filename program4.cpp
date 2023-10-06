#include<iostream>

using namespace std;

void Display(int iRow,int iCol)
{
    int i=0,j=0;
    for ( i = 1; i<=iRow; i++)
    {
        for(j=1;j<=iCol;j++)
        {
            if(j==3 || i==3)
            {
                cout<<" * ";
            }
            else
            {
                cout<<"   ";
            } 

        }
        cout<<"\n";

    }
    

}


int main()
{
    int iRow=0,iCol=0;

    cout<<"Enter rows\n";
    cin>>iRow;

    cout<<"Emter coloumns\n";
    cin>>iCol;

    Display(iRow,iCol);


    return 0;
}
