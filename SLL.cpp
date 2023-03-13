#include<iostream>
using namespace std;
class SLL //Singly Linked List
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *start;
public:
    SLL();
    void InsertatFirst(int data);
    void InsertatLast(int data);
    node* Search(int element);//1st Occurrence
    void InsertAfternode(int element,int data);
    void DeleteFirst();
    void DeleteLast();
    void DeleteParticularNode(int element);
    void View();
    ~SLL();
};
SLL::SLL()
{
    start=NULL;
}
void SLL::InsertatFirst(int data)
{
    node *t=new node;
    t->item=data;
    t->next=start;
    start=t;
}
void SLL::InsertatLast(int data)
{
    node *t=new node;
    t->item=data;
    t->next=NULL;

    if(start=NULL)
        start=t;
    else
    {
        node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=t;
    }
}
SLL::node* SLL::Search(int element)
{
    node *temp=start;
    while(temp!=NULL)
    {
        if(temp->item==element)
            return temp;
        temp=temp->next;
    }
    return NULL;
}
void SLL::InsertAfternode(int element,int data)
{
    if(start==NULL)
        cout<<"Linked List is Empty";
    else
    {
       node *temp=Search(element);
       if(temp==NULL)
        cout<<"Element Not Found";
       else
       {
           node *t=new node;
           t->item=data;
           t->next=temp->next;
           temp->next=t;
       }
    }
}
void SLL::DeleteFirst()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=start;
        start=start->next;
        delete temp;
    }
}
void SLL::DeleteLast()
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
        if(t2=NULL) //That means t1 is pointing first node of Linked List
            start=NULL;  //Or start=t2;  //Or  start=t1->next;
        else
            t2->next=NULL; //Or t2->next=t1->next;
        delete t1;
    }
}
void SLL::DeleteParticularNode(int element)
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=Search(element);
        if(temp==NULL)
            cout<<"Element Not Found";
        else
        {
            node *t=start;
            if(t==temp)
                start=t->next; //Or start=temp->next;
            else
            {
               while(t->next!=temp)
                 t=t->next;
               t->next=temp->next;
            }
            delete temp;
        }
    }
}
void SLL::View()
{
    if(start==NULL)
        cout<<"Linked list is Empty";
    else
    {
        cout<<"List are :";
        node *temp=start;
        while(temp!=NULL)
        {
            cout<<"  "<<temp->item;
            temp=temp->next;
        }
    }
}
SLL::~SLL()
{
    while(start)
       DeleteFirst();
}
