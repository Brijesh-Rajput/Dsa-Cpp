//practice for insertion in priority queue using linked list
//plzz consider all the condition Don't hurry up
#include<iostream>
#include<stdio.h>
using namespace std;
class priority_Queue_LL
{
private:
    struct node
    {
        int pr;   //store priority NO.
        int item;
        node *next;
    };
    node *start; //work as a front for deletion from highest priority no.
public:
    priority_Queue_LL();
    void insert(int pr,int data);
    void Delete();
    void view();
    ~priority_Queue_LL();
};
priority_Queue_LL::priority_Queue_LL()
{
    start=NULL;
}
void priority_Queue_LL::insert(int pr,int data)
{
    node *t=new node;
    t->pr=pr; //Very IMP //this pointer will use or not ??? Confusion
    t->item=data;               //this pointer is used for calling object

    node *t2=NULL,*t1=start;
    while(t1!=NULL && t1->pr>=t->pr)  //t1!=NULL is for when data is enter at last
    {
        t2=t1;
        t1=t1->next;
    }
    if(t2==NULL)
    {//when start==NULL Or when we have to insert as a front b'coz of higher priority
        t->next=start; //Or t->next=t1;
        start=t;
    }
    else
    {
        t->next=t2->next;
        t2->next=t;
    }
}
void priority_Queue_LL::Delete()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=start;
        start=start->next; //Or start=temp->next;
        delete temp;
    }
}
void priority_Queue_LL::view()
{
    node *temp=start;
    while(temp!=NULL)
    {
        cout<<temp->pr<<"-"<<temp->item<<"  ";
        temp=temp->next;
    }
    cout<<endl<<endl;
}
priority_Queue_LL::~priority_Queue_LL()
{
    while(start)
        Delete();
}
int main()
{
    cout<<"i for no. of queues and j for no. values in each queue(rear)\n"; //copy from priority queue _Array
    priority_Queue_LL p1;
    p1.insert(1,12);
    p1.insert(0,45);
    p1.view();
    p1.insert(2,37);
    p1.insert(3,57);
    p1.view();
    p1.insert(1,43);
    p1.view();
    p1.insert(0,38);
    p1.insert(4,52);
    p1.view();
    p1.insert(5,1);
    p1.insert(3,24);
    p1.insert(5,450);
    p1.view();
    p1.insert(3,276);
    p1.insert(5,356);
    p1.view();
    p1.insert(4,158);
    p1.insert(3,06);
    p1.view();
    p1.insert(2,267);
    p1.insert(7,541);
    p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
    p1.view();
     p1.insert(1,5461);
     p1.view();
    p1.insert(9,8);
    p1.view();
    p1.insert(4,222);
    p1.view();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
}
/*
void priority_Queue_LL::insert(int pr,int data)
{
    node *t=new node;
    t->pr=pr; ///Very IMP //this pointer will use or not ??? Confusion
    t->item=data;               //this pointer is used for calling object

    if(start==NULL)
    {
         t->next=start; //t->next= NULL;
         start=t;
    }
    else
    {
       node *t2=NULL,*t1=start;
       while(t1!=NULL && t1->pr>=t->pr)  //t1!=NULL is for when data is enter at last
       {
           t2=t1;
           t1=t1->next;
       }
       if(t2==NULL)
       {
           t->next=start; //Or t->next=t1;
           start=t;
       }
       else
       {
           t->next=t2->next;
           t2-next=t;
       }
    }
}
*/
/*
r=pr; ///Very IMP //this pointer will use or not ??? Confusion
    t->item=data;               //this pointer is used for calling object

    if(start==NULL)
    {
         t->next=start; //t->next= NULL;
         start=t;
    }
    else
    {
       node *t2=NULL,*t1=start;
       while(t1->pr>=t->pr && t1!=NULL )  //t1!=NULL is for when data is enter at last
       {
           t2=t1;
           t1=t1->next;
       }
       if(t2==NULL)
       {
           t->next=start; //Or t->next=t1;
           start=t;
       }
       else
       {
           t->next=t2->next;
           t2-next=t;
       }
    }
}
*/
/*
void priority_Queue_LL::insert(int pr,int data)
{
    node *t=new node;
    t->pr=pr; ///Very IMP //this pointer will use or not ??? Confusion
    t->item=data;               //this pointer is used for calling object

    if(start==NULL)
    {
         t->next=start; //t->next= NULL;
         start=t;
    }
    else
    {
        node *temp=start;
        if(temp->pr<t->pr && temp==start) //when 1st node
        {
            t->next=start;  //t->next=temp;
            start=t;
        }
        else
        {
            while(temp->next->pr>=t->pr)
             {
                 temp=temp->next;
                 if(temp->next==NULL)
                    break;
             }
            t->next=temp->next;
            temp->next=t;
        }
    }
}
*/
/*
void priority_Queue_LL::insert(int pr,int data)
{
    node *t=new node;
    t->pr=pr; ///Very IMP //this pointer will use or not ??? Confusion
    t->item=data;               //this pointer is used for calling object

    if(start==NULL)
    {
         t->next=start; //t->next= NULL;
         start=t;
    }
    else
    {
        node *temp=start;
        while(t->pr<=temp->pr)
        {

        }
        if(temp==start)
        {
            t->next=start;
            start=t;
        }
        else
        {

        }
    }
*/
