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
    void InsertAfternode(int element,int data);//insert data after the node whose item has element---->1st Occurrence will be consider here
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
    start=t;//B'coz t is a pointer of node type and its store address of node type
}
void SLL::InsertatLast(int data)
{
    node *t;
    t=new node;
    t->item=data;
    t->next=NULL;

    node *temp;
    temp=start;

    if(temp==NULL)
        start=t;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=t;
    }
}
//void SLL::InsertAfternode(int data){....} //we can use search function inside it but if not found it return -1
void SLL::InsertAfternode(int element, int data) //we can use search function to find the element in the List
{
    if(start==NULL)
        cout<<"Element is not found";
    else
    {
        node *temp;
        temp=start;

        while(temp->item!=element)
        {
             if(temp->next==NULL)
             {
                 cout<<"Element is Not found";
                 break;
             }
             temp=temp->next;
        }
        if(temp->item==element) //b'coz when NO element found then temp is pointing to the last node that's why here condition are applying
        {
            node *t;
        // t->item=data; //DON'T DO THIS MISTAKE //Very IMP //till now, only pointer is made of node type not Dynamically Node
            t=new node;
            t->item=data;
            t->next=temp->next; //If temp->next contains NULL, then also it is valid
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
        node *temp;
        temp=start; //we cann't write this before if body b'coz when start contains NULL then it's waste of time to make a node pointer and stores NULL which was in start, so we have written this in else part NOT in if part

        start=temp->next;
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
        t2=NULL; //t2 is pointing to the previous node of t1
// Here, t1 is pointing to the 1st node that means there is no node before it therefore t2 pointer contains NULL
// there is no required two pointer in DLL, B'coz in that, node has previous pointer variable which contains address of previous node
        while(t1->next!=NULL)
        {
           // t1=t1->next; wrong!!!  B'coz, suppose if you did this then how you will assign the address of previous node
           t2=t1;
           t1=t1->next;
        }
        if(t2==NULL)
           start=NUll; //OR start=t1->next;
        else
           t2->next=t1->next;
        delete t1;
    }
}void SLL::DeleteNode(int element)
{//To search the Element we can use Search function
    //so, Before writing the function code ,1stly see the function which we want to make later if that function is useful in any code then 1st make that function and used it in the function in which it will be used
    if(start==NULL)
        cout<<"Element is not found Or Underflow Or List is Empty";
    else
    {
        node *t1,*t2;
        t1=start;
        t2=NULL;

        while(t1->item!=element)
        {
            if(t1->next==NULL)
            {
                cout<<"Element is NOT found";
                break;
            }
            t2=t1;
            t1=t1->next;
        }
        if(t1->item==element)
        {//IMP--->>>>
            //if there is ony one node and element is found in the list
            if(t2==NULL)
                //this is wrong----> start=NULL; //Or start=t2;
                //B'coz when element is found in 1st node and there is more than 1 node in the list then start contains NULL which is BLUNDER MISTAKE. By this, Memory Leakage will also happen
//Very IMP-->>  //so Don't put directly anything, instead of this ,put the value like below
               //if t1->next contains NULL then also it is Valid
               start=t1->next;
            else
                t2->next=t1->next;
            delete t1;
        }
    }
}
void SLL::view()
{
    if(start==NULL)
        cout<<"List is Empty"; //Acc. to me no need to write if condition but by writing this client can know easily that list is empty
    else
    {
        node *temp;
        temp=start;

        while(temp!=NULL)
        {
            cout<<" "<<temp->item;
            temp=temp->next;
        }
    }
}
node* SLL::search(int element)
{
    if(start==NULL)
        cout<<"List is Empty";
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
        return NULL; //Or Acc. to me, we can also return -1
    //there is benefit to return NULL --->>>in insert item after node function and in delete particular node function
    }
}
SLL::~SLL()
{
    while(start!=NULL)
        DeleteFirst();
    /*
    while(start!=NULL)
        DeleteLast();
    */
}
/*  wrong
//B'coz when List is Empty then below code is right, But when element is present in the List that means List is Not Empty then all elements will print one by one and after printing all the elements of the list
//condition will become false and then last line will print which was (List is Empty) that was wrong
void SLL::view()
{
        node *temp;
        temp=start;

        while(temp!=NULL)
        {
            cout<<" "<<temp->item;
            temp=temp->next;
        }
        cout<<"List is Empty";
}
*/
/* wrong
void SLL::DeleteNode(int element,int data)
{
    if(start==NULL)
        cout<<"Element is not found Or Underflow Or List is Empty";
    else
    {
        node *temp;
        temp=start;

        while(temp->item!=element)
        {
            if(temp->next==NULL)
            {
                cout<<"Element is NOt found";
                break;
            }
            temp=temp->next;
        }
        if(temp->item==element)
            //Here we require two node pointer to delete the previous node of node at which element is found
    }
}
*/
/* Or
void SLL::DeleteLast()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp;
        temp=start;

        if(start->next==NULL)
        {
            start=start->next;
            delete temp;
        }
        else
        {
            while(temp->next->next!=NULL)
                temp=temp->next;
            delete temp->next;
            temp->next=NULL;
        }
    }
}
*/
/* OR
void SLL::DeleteLast()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        if(start->next==NULL)
        {
            delete start;
            start=NULL;

            /* OR
            node *temp;
            temp=start;
            start=start->next;
            delete temp;
            */
        }
        else
        {
            node *temp;
            temp=start;

            while(temp->next->next!=NULL)
                temp=temp->next;
            delete temp->next;
            temp->next=NULL;
            /* this is wrong
            temp->next=temp->next->next;
            delete temp->next;
            B'coz temp->next is Now containing NULL, so this will become Memory Leakage Condition
            */
        }
    }
}
*/
/*
void SLL::InsertAfternode(int element, int data)
{
    if(start==NULL)
        cout<<"Element is not found";
    else
    {
        node *temp;
        temp=start;

        while(temp->item!=element)
        {
           //  temp=temp->next;  it should be after the condition
           /*
             if(temp==NULL)
             {
                 cout<<"Element is Not found";
                 break;
             }
           */
             if(temp->next==NULL)
             {
                 cout<<"Element is Not found";
                 break;
             }
             temp=temp->next;
        }

    }
}
*/
