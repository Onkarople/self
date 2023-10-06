#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

};

typedef struct node NODE;
typedef struct node* PNODE;


class DLL
{
    public:
     PNODE Head;
     PNODE tail;
     int count;

    DLL();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtpos(int,int);
    void DeleteAtpos(int);
    void Display();
    int countNode();


};

DLL::DLL()
{
    Head=NULL;
    tail=NULL;
    count=0;
}

void DLL::InsertFirst(int no)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->next=NULL;
    newn->data=no;

    if(Head==NULL && tail==NULL)
    {
        Head=newn;
        tail=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    tail->next=Head;
    count++;
}

void DLL::InsertLast(int no)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->next=NULL;
    newn->data=no;

    if(Head==NULL && tail==NULL)
    {
        Head=newn;
        tail=newn;
    }
    else
    {
       tail->next=newn;
       tail=newn;
    }
    tail->next=Head;
    count++;
}


void DLL::DeleteFirst()
{
    if(Head==NULL && tail==NULL)
    {
        return;

    }
    else if(Head==tail)
    {
        Head=NULL;
        tail=NULL;
    }
    else
    {
        Head=Head->next;
        delete tail->next;

    }
    tail->next=Head;
    count--;

    
}

void DLL::DeleteLast()
{
     if(Head==NULL && tail==NULL)
    {
        return;

    }
    else if(Head==tail)
    {
        Head=NULL;
        tail=NULL;
    }
    else
    {
       PNODE temp=Head;
       while(temp->next!=tail)
       {
        temp=temp->next;
       }
       delete tail;
       tail=temp;

    }
    tail->next=Head;
    count--;
}

void DLL::InsertAtpos(int no,int pos)
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

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

    }
    count++;
}

void DLL::DeleteAtpos(int pos)
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
        PNODE tempDelete=NULL;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        tempDelete=temp->next;
        temp->next=temp->next->next;
        delete tempDelete;
        

    }
    count--;
}

void DLL::Display()
{
    PNODE temp=Head;

    if(Head==NULL && tail==NULL)
    {
        return;
    }
    do{
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }while (temp!=Head);

    cout<<endl;
    
}

int DLL::countNode()
{
    return count;
}



int main()
{
    DLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);

    obj.Display();

    cout<<"count is:"<<obj.countNode()<<endl;

    obj.InsertAtpos(75,4);
    obj.Display();

    cout<<"count is:"<<obj.countNode()<<endl;

    obj.DeleteAtpos(4);
    obj.Display();

    cout<<"count is:"<<obj.countNode()<<endl;







    return 0;
}
