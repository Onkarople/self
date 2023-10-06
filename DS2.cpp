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

class DLS
{
    public:
      PNODE Head;
      int count;

    DLS();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtpos(int no,int pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtpos(int);
    void Display();
    int countNode();
};


DLS::DLS()
{
    Head=NULL;
    count=0;
}

void DLS::InsertFirst(int no)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL)
    {
        Head=newn;

    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }
    count++;
}

void DLS::InsertLast(int no)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

   

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
      newn->prev=temp;


    }
    count++;
}

void DLS::DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else
    {
        Head=Head->next;
        delete Head->prev;
        Head->prev=NULL;
    }
    count--;
}

void DLS::DeleteLast()
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

void DLS::Display()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

void DLS::InsertAtpos(int no,int pos)
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
      PNODE temp=Head;
      PNODE newn=NULL;
      newn=new NODE;

      newn->data=no;
      newn->next=NULL;
      newn->prev=NULL;

      for(iCnt=1;iCnt<pos-1;iCnt++)
      {
        temp=temp->next;
      }

      newn->next=temp->next;
      temp->next->prev=newn;
      temp->next=newn;
      newn->prev=temp;

   }
   count++;

}

void DLS::DeleteAtpos(int pos)
{
    if(pos<1||pos>count)
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
     

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }

        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
    }
}

int DLS::countNode()
{
    return count;
}




int main()
{
    DLS obj;

   obj.InsertFirst(11);
   obj.InsertFirst(21);
   obj.InsertLast(51);
   obj.InsertLast(101);
   obj.InsertAtpos(75,4);


   obj.Display();

   cout<<"Count Is:"<<obj.countNode()<<endl;

   obj.DeleteFirst();
   obj.DeleteLast();


   obj.Display();

   cout<<"Count Is:"<<obj.countNode()<<endl;

   obj.DeleteAtpos(2);

   obj.Display();


    return 0;
}