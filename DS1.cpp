#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node* next;

};

typedef struct node  NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


class Ds
{
    public:
    PNODE Head;
    int count;

    Ds();
    void InsertFirst(int iNo);
    void InsertLast(int no);
    void InsertAtPos(int,int);
    void DeleteLast();
    void DeleteFirst();
    void DeleteAtPos(int pos);
    int CountNode();
    void Display();

};


Ds::Ds()
{
    Head=NULL;
    count=0;
}

 void Ds::InsertFirst(int no)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=no;
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
    count++;
   
}


void Ds::InsertLast(int no)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=no;
    newn->next=NULL;


    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        PNODE temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    count++;

}

void Ds::DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else
    {
        PNODE temp=Head;
        Head=Head->next;
        delete temp;
    }
    count--;

}

void Ds::DeleteLast()
{
    if(Head==NULL)
    {
        return;
    }
    else
    {
        PNODE temp=Head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    count--;
}


void Ds::InsertAtPos(int no,int pos)
{
   

    if(pos<1||pos>count+1)
    {
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==count+1)
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
        count++;


    }
}


void Ds::DeleteAtPos(int pos)
{
    if(pos<1||pos>>count)
    {
        return;
    }

    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==count)
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
        count--;
        
    }



}


void Ds::Display()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL "<<endl;
}

int Ds::CountNode()
{
    return count;
}

int main()
{
    Ds obj;
    int iRet=0;

   obj.InsertFirst(11);
   obj.InsertFirst(21);
   obj.InsertLast(51);
   obj.InsertLast(101);
   obj.InsertAtPos(75,4);

   obj.Display();

   cout<<"Count Is:"<<obj.CountNode()<<endl;

   obj.DeleteFirst();
   obj.DeleteLast();


   obj.Display();

   cout<<"Count Is:"<<obj.CountNode()<<endl;

   obj.DeleteAtPos(2);

   obj.Display();



    return 0;
}