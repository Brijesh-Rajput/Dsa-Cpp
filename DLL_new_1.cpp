#include<iostream>
#include<stdio.h>
using namespace std;
class DLL  //Doubly Linked List
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
    DLL();
    void InsertatFirst(int data);
    void InsertatLast(int data);
    void InsertafterNode(int element,int data);
    void DeleteFirst();
    void DeleteLast();
    void DeleteNode(int element);
    node* search(int element);
    void view();
    ~DLL();
};
DLL::DLL()
{
    start=NULL;
}
void DLL::InsertatFirst(int data)
{
    node *t=new node;
    t->prev=NULL;
    t->item=data;
    t->next=start;
    if(start!=NULL)
      start->prev=t; //Or t->next->prev=t;
    start=t;
}
void DLL::InsertatLast(int data)
{
    node *t=new node;
    t->item=data;
    t->next=NULL;

    node *temp;
    temp=start;

    if(start==NULL)
    {
       t->prev=NULL;
       start=t;
    }
    else
    {
      while(temp->next!=NULL)
         temp=temp->next;
      t->prev=temp;
      temp->next=t;
    }
}
node* DLL::search(int element) ///Error:-'node' does not name a type; did you mean 'mode_t'
{  //--------------------->>>>>>>> Below  Sir code----------------------------------<<<<<
    if(start!=NULL) //else--> Linked List is Empty
    {
        node *temp;
        temp=start;

        while(temp->item!=element)
        {
            if(temp->next==NULL)
                break;
            temp=temp->next;
        }
        if(temp->item==element)
            return temp;  // when 1st Occurrence of data is matched with the given element then its address will return
    }                     //address of 1st Occurrence of data is returning
    return NULL;
}
/* sir code
node* search(int data)
{
 node *t=start;
 while(t!=NULL)
 {
   if(t->item==data)
    return t;
   t=t->next;
 }
 return NULL;
}
*/
void DLL::InsertafterNode(int element,int data)
{
    node *t;
    t=search(element);
    if(t==NULL)
        cout<<"Element is Not found so, Insertion failed";
    else
    {
        node *n=new node;
        n->prev=t;
        n->item=data;

        n->next=t->next;
        if(t->next!=NULL)
           t->next->prev=n;
        t->next=n;
    }
}
void DLL::DeleteFirst()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
       node *temp=start;
       start=temp->next;
       if(start!=NULL)
         start->prev=NULL;
       delete temp;
    }
}
void DLL::DeleteLast()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *t1,*t2;
        t1=start;
        t2=NULL;

        while(t1->next!=NULL)
        {
            t2=t1;
            t1=t1->next;
        }
        if(t2==NULL)
            start=NULL;  //start=t2; //start=t1->next;
        else
           t2->next=t1->next;  //t2->next=NULL;
        delete t1;
    }
}
void DLL::DeleteNode(int element) //my code is simple --> sLL me jo concept use kiya hai vo chota hai
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=search(element);
        if(temp==NULL)
            cout<<"Element Not Found";
        else
        {
            node *t1,*t2;
            t1=start;
            t2=NULL;
            while(t1!=temp)
            {
                t2=t1;
                t1=t1->next;  //t1 cann't be NULL
            }
            if(t2==NULL)
                start=t1->next;
            else //(t2!=NULL)
              t2->next=t1->next;
            if(t1->next!=NULL)
               t1->next->prev=t2;
            delete temp; //Or delete t1;
        }
    }
}
void DLL::view()
{
    if(start==NULL)
        cout<<"List are Empty";
    else
    {
        cout<<"List are :";
        node *t=start;
        while(t!=NULL)   //Don't use this  t->next!=NULL
        {
            cout<<"  "<<t->item;
            t=t->next;
        }
    }
}
DLL::~DLL()
{
    while(start)
        DeleteFirst();
}
