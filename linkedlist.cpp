#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;

class SLL
{
    public:
     PNODE Head;
     int Cnt;
    
    SLL();
    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int,int);
    void DeleteAtPos(int pos);
    void DeleteFiirst();
    void DeleteLast();
    int Count();
    void Display();
};

SLL::SLL()
{
    Head=NULL;
    Cnt=0;
}

void SLL::InsertFirst(int No)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=No;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    Cnt++;

}


void SLL::InsertLast(int No)
{
    PNODE newn=NULL;
    PNODE temp=Head;

    newn=new NODE;

    newn->data=No;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        
    }
    Cnt++;


}


void SLL::DeleteFiirst()
{
    PNODE temp=NULL;
 
    if(Head==NULL)
    {
        return;
    }
    else
    {
      temp=Head;
      Head=Head->next;
      delete temp;
   
    }
    Cnt--;


}

void SLL::DeleteLast()
{
    PNODE temp=NULL;
    if(Head==NULL)
    {
        return;
    }
    else
    {
      temp=Head;
      while(temp->next->next!=NULL)
      {
        temp=temp->next;
      }
      delete temp->next;
      temp->next=NULL;

    }
    Cnt--;

}


void SLL::InsertAtPos(int no,int pos)
{
   

    if(pos<1||pos>Cnt+1)
    {
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==Cnt+1)
    {
        InsertLast(no);
    }
    else
    {
        int iCnt=0;
        PNODE newn=NULL;
        PNODE temp=Head;
        newn=new NODE;

        newn->data=no;
        newn->next=NULL;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next=newn;
        Cnt++;


    }
}


void SLL::DeleteAtPos(int pos)
{
    if(pos<1||pos>>Cnt)
    {
        return;
    }

    if(pos==1)
    {
        DeleteFiirst();
    }
    else if(pos==Cnt)
    {
        DeleteLast();
    }
    else
    {
        int iCnt=0;
        PNODE temp=Head;
        PNODE tempDelete=NULL;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }

        tempDelete=temp->next;
        temp->next=temp->next->next;
        delete tempDelete;
        Cnt--;
        
    }



}

void SLL::Display()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL "<<endl;

}

int SLL::Count()
{
   return Cnt;
}

int main()
{
    SLL obj;
    int Ret=0;

    obj.InsertFirst(10);
    obj.InsertFirst(11);
    obj.InsertLast(20);
    obj.InsertLast(30);
    obj.InsertLast(50);
    obj.InsertAtPos(75,4);

    obj.Display();
    obj.DeleteFiirst();
   
    obj.Display();
    obj.DeleteLast();
    obj.Display();

    obj.DeleteAtPos(2);
    obj.Display();


    Ret=obj.Count();
    cout<<Ret;
    


    return 0;
}