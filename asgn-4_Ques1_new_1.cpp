//see my previous code of SLL and my mistake and wrong code
#include<iostream>
#include<conio.h>
#include<stdio.h> //for NULL
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
    void InsertAfternode(int element,int data);//insert data after the node whose item has given element---->1st Occurrence will be consider here
    void DeleteFirst();
    void DeleteLast();
    void DeleteNode(int element); //Delete that node whose element is given
    void view();
    node* search(int data);
    ~SLL();
};
SLL::SLL()
{
    start=NULL;
}
void SLL::InsertatFirst(int data)
{
    node *t;
    t=new node;
    t->item=data;
    t->next=start;
    start=t;//B'coz  t is a pointer of node type and its store address of node type
}
void SLL::InsertatLast(int data)
{
    node *t;
    t=new node;
    t->item=data;
    t->next=NULL;

    node *temp;
    temp=start;

    if(temp==NULL) //that means start contains NULL and there is no nodes Or no element is present in the list
        start=t;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=t;
    }
}
void SLL::InsertAfternode(int element, int data)
{
    node *t;
    t=search(element);
    if(t==NULL)
       cout<<"Element is NOT found";
    else
    {
        node *temp;
        temp=new node;
        temp->item=data;
        temp->next=t->next;
        t->next=temp;
    }
}
void SLL::DeleteFirst()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp;
        temp=start;
        start=temp->next;
        delete temp;
    }
}
void SLL::DeleteLast() //IMP ,Here two condition --> if one node present then changes will be done in start
{                                                 // if more than one node present then changes will done in next pointer variable of 2nd last node
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *t1,*t2;
        t1=start;
        t2=NULL;
        while(t1->next!=NULL)
        {
           // t1=t1->next; wrong!!!  B'coz, suppose if you did this then how you will assign the address of previous node
           t2=t1;
           t1=t1->next;
        }
        if(t2==NULL)
           start=t1->next;  //Or start=NUll;   //Or start=t2;
        else
           t2->next=t1->next;  //t2->next=NULL; //we can write here, b'coz t1->next contains NULL we confirm it b'coz when t1->next contains NULL then and then only control will come out from loop
//IMP   //But its a good practice to write like this ----> t2->next=t1->next;    To Avoid any MISTAKE
        delete t1;
    }
}
void SLL::DeleteNode(int element)
{
    node *temp;
    temp=search(element);
    if(temp==NULL)
        cout<<"Element NOt found";
    else
    {
        if(start==temp)
          start=temp->next;
        else
        {
           node *t;
           t=start;
           while(t->next!=temp)
              t=t->next;
           t->next=temp->next;
        }
        delete temp;
    }
}
void SLL::view()
{
    if(start==NULL)
        cout<<"List is Empty";
    else
    {
        cout<<"List Items are :";
        node *temp;
        temp=start;

        while(temp!=NULL)//we can use here do while loop with this condition temp->next!=NULL try this with do while loop
        {
            cout<<" "<<temp->item;
            temp=temp->next;
        }
    }
}
node* SLL::search(int element)
{
    if(start==NULL);//return NULL
    else
    {
        node *temp;
        temp=start;

        while(temp->item!=element)
        {
            if(temp->next==NULL)
            {
                cout<<"Element is NOT found";
                break;
            }
            temp=temp->next;
        }
        if(temp->item==element) //B'coz when element is not found then we came out from the loop so, there is need to check the condition
            return temp;
    }
    return NULL; //Why NOT -1;
}
SLL::~SLL()
{
    while(start!=NULL)
        DeleteFirst();

    /* OR
    while(start)
        DeleteFirst();
    */

//Don't write below code instead of above code B'coz in below while loop, DeleteLast() function is used
//AND DeleteLast() function takes more time comparison to DeleteFirst() function B'coz traversing is required in DeleteLast() function to delete Last Node
    /*
    while(start!=NULL)
        DeleteLast();
    */
}
