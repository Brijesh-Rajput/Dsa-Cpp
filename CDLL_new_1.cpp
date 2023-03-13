#include<iostream>
#include<stdio.h>
using namespace std;
class CDLL //Circular Doubly Linked List
{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;
    };
    node *start;
public:
    CDLL();
    void InsertatFirst(int data);
    void InsertatLast(int data);
    void InsertafterNode(int element,int data);
    void DeleteFirst();
    void DeleteLast();
    void DelteParticularNode(int element); //DeleteParticularItem of List
    node* search(int element); //It returns the Address of node at which 1st Occurrence of element is found in the list
    void view();
    ~CDLL();
};
CDLL::CDLL()
{
    start=NULL;
}
void CDLL::InsertatFirst(int data)
{
    node *t=new node;
    t->item=data;

    if(start==NULL)
    {
        t->next=t;
        t->prev=t;
    }
    else
    {
       t->next=start;
       t->prev=start->prev;

       start->prev->next=t;
       start->prev=t;
    }
    start=t;
}
void CDLL::InsertatLast(int data)
{
    node *t=new node;
    t->item=data;

    if(start)
    {
      t->next=start->prev->next;
      t->prev=start->prev;

      start->prev->next=t;
      start->prev=t;
    }
    else
    {
      t->prev=t;
      t->next=t;
      start=t;
    }
}
node* CDLL::search(int element) //Address of 1st Occurrence of element will return if element will found in the list
{           //Do-While LOOP
    if(start)
    {
        node *temp=start;
        do
        {
            if(temp->item==element)
                return temp;//returns address of node at which element is matched or found in the list
            temp=temp->next;
        }while(temp!=start);
    }
    return NULL;
}
void CDLL::InsertafterNode(int element,int data)
{
    if(start==NULL)
        cout<<"List are Empty";
    else
    {
        node *temp=search(element);
        if(temp==NULL)
            cout<<"Element Not found";
        else //temp!=NULL
        {
            node *t=new node;
            t->item=data;

            t->prev=temp;
            t->next=temp->next;

            temp->next->prev=t;
            temp->next=t;

        }
    }
}
void CDLL::DeleteFirst()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=start;
        if(start->next==start)
           start=NULL;
        else
        {
            start->next->prev=start->prev;
            start->prev->next=start->next;
            start=start->next;
        }
        delete temp;
    }
}
void CDLL::DeleteLast()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=start->prev;
        if(start->next==start) //Or start->prev==start
            start=NULL;
        else
        {
           temp->prev->next=temp->next;
           start->prev=temp->prev;
        }
        delete temp;
    }
}
void CDLL::DelteParticularNode(int element)
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=search(element); //search functions returns address of node at which 1st  Occurrence of element if it is found in the list
        if(temp==NULL)
            cout<<"Element Not found in the list";
        else //Deletion can perform if control comes in else part
        {
            if(temp==start)
                DeleteFirst();
            else if(temp==start->prev)
                DeleteLast();
            else
            {
               temp->prev->next=temp->next;
               temp->next->prev=temp->prev;
               delete temp;
            }
        }
    }
}
void CDLL::view()
{
    if(start==NULL)
        cout<<"List are empty";
    else
    {
        cout<<"List are :";
        node *temp=start;
        do
        {
            cout<<"  "<<temp->item;
            temp=temp->next;
        }while(temp!=start);
    }
}
CDLL::~CDLL()
{
    while(start)
        DeleteLast(); //DeleteFirst() takes More time
}
int main()
{

}

/*
when we will use DeleteFirst() instead of DeleteLast() in Destructor then, it takes more time b'coz we have to change every time in start pointer variable whenever Deletefirst() function will call
that means, suppose if we have 5 nodes in the linked list (5 items are present in the list) then 4 steps will execute more when we use DeleteFirst function in  the Destructor compare to DeleteLast function.
B'coz Every time changes are happening in the start pointer variable when DeleteFirst function call.
B'coz Traversing is not happening in any of the function(DeleteFirst() & DeleteLast())
Approximately both function takes similar time but One more steps is happening in the DeleteFirst() Function Compare to DeleteLast function()
so, to use DeleteLast() function is best in destructor
*/
/* Or
    while(start)
        DeleteLast();
    */
    /* while(start!=NULL)
       DeleteFirst();
    */

/*
for Deletelast()
    when two nodes are present in the list then after deleting last node, one node will left in the linked list
    node->next==node->prev==start
*/
/*  //Or
          node *temp=start->next;
          temp->prev=start->prev;
          start->prev->netx=temp;
          delete start;
          start=temp;
        */

        /*
        start->next->prev=start->prev;
        start->prev-next=start->next;
        delete start;
        start=start->next;
        */
