#include<iostream>
#include<stdio.h>
using namespace std;
class CLL //Circular Linked List
{
private:
    struct node
    {
        int item;
        node* next;
    };
    node *last;
public:
    CLL();
    void InsertatFirst(int data);
    void InsertatLast(int data);
    void InsertafterNode(int element,int data);
    void DeleteFirst();
    void DeleteLast();
    void DeleteParticularNode(int element); //1st Occurrence will be consider
    node* search(int element);
    void view();
    ~CLL();
};
CLL::CLL()
{
    last=NULL;
}
void CLL::InsertatFirst(int data)
{
    node *t=new node;
    t->item=data;

    if(last==NULL)//List are Empty
    {
        t->next=t;
        last=t;
    }
    else
    {
        t->next=last->next;
        last->next=t;
    }
}
void CLL::InsertatLast(int data)
{
    node *t=new node;
    t->item=data;

    if(last==NULL)
        t->next=t;
    else
    {
        t->next=last->next;
        last->next=t;
    }
    last=t;
}
node* CLL::search(int element)
{
    if(last==NULL) //Empty List
        return NULL;
    node *t=last;
    do
    {
        if(t->item==element)
            return t;
        t=t->next;
    }while(t!=last);
    return NULL;
}
void CLL::InsertafterNode(int element,int data)
{
    node *t=search(element);
    if(t==NULL)
        cout<<"Element Not found";
    else //search function returns the address of 1st Occurrence of element in the list
    {    //so that new data will insert as a node after 1st occurrence of element in the list
        node *temp=new node;
        temp->item=data;

        temp->next=t->next;
        t->next=temp;
        if(t==last)
          last=temp;
    }
}
void CLL::DeleteFirst()
{
    if(last==NULL)
        cout<<"Underflow";
    else
    {
        node *t=last->next;
        if(t==last)//Condition for single Node
            last=NULL;
        else
            last->next=t->next;
        delete t;
    }
}
void CLL::DeleteLast()
{
    if(last==NULL)
        cout<<"Underflow";
    else
    {
        node *t=last;
        if(t->next==last)
            last=NULL;
        else
        {
            node *temp=last; //This line sir code
            while(temp->next!=last) //when temp pointer variable pointing 2nd last node then control will come out from while loop
                temp=temp->next;
            temp->next=t->next;
            last=temp;
        }
        delete t;
    }
}
void CLL::DeleteParticularNode(int element)
{
    if(last==NULL)
        cout<<"Underflow";
    else
    {
        node *t=search(element);
        if(t==NULL)
            cout<<"Element Not Found";
        else
        {
           if(last->next==last)
                last=NULL;
           else
           {
              node *temp=last;
              while(temp->next!=t)
                 temp=temp->next;
              temp->next=t->next;
              if(t==last)
                last=temp;
           }
           delete t;
        }
    }
}
void CLL::view() //Do-while loop used
{
    if(last==NULL)
        cout<<"List are Empty";
    else
    {
        cout<<"List are :";
        node *t=last->next;
        do
        {
            cout<<"  "<<t->item;
            t=t->next;
        }while(t!=last->next);
    }
}
CLL::~CLL()
{
    while(last)
     DeleteFirst();
}
