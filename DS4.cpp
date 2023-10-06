#include<iostream>
using namespace std;


struct node
{
   int data;
   struct node *next;
   struct node *prev;


};


typedef struct node NODE;
typedef struct node * PNODE;


class DCLL
{
    public:
     PNODE head;
     PNODE tail;
     int count;

     DCLL();
     void InsertFirst(int);
     void InsertLast(int);
     void DeleteFirst();
     void DeleteLast();
     void InsertAtpos(int,int);
     void DeleteAtpos(int);
     void Display();
     int countNode();


};

DCLL::DCLL()
{
    head=NULL;
    tail=NULL;
    count=0;
}



int main()
{

    return 0;
}
