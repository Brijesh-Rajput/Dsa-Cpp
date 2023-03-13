
#include<iostream>
#include<stdio.h>
using namespace std;
class Queue_SLL
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *rear,*front;
public:
    Queue_SLL();
    void Insert(int data);
    void Delete();
    void view();
    int count();
    ~Queue_SLL();
};
Queue_SLL::Queue_SLL()
{
    rear=NULL;
    front=NULL;
}
void Queue_SLL::Insert(int data)
{
    node *t=new node;
    t->item=data;
    t->next=NULL;

    if(rear==NULL) //that means front point 1st element of queue
      front=t;
    else   //that means front point 1st element of queue
       rear->next=t;
    rear=t;
}
void Queue_SLL::Delete()
{
    if(front==NULL)
        cout<<"Underflow"<<endl;  //here invalid operation will  not come as like in queue_Array b'coz there is ptr which points dynamically array when array is not created by dynamically then how deletion will perform hats why Invalid operation
    else if(front==rear)
    {
        delete front;
        front=NULL;
        rear=NULL;
    }
    else
    {
        node *temp=front;
        front=front->next;
        delete temp;
    }
}
void Queue_SLL::view()
{
    if(front==NULL)
        cout<<"Empty Queue";
    else
    {
        cout<<"Queue :";
        node *temp=front;
        while(temp!=NULL)
        {
            cout<<"  "<<temp->item;
            temp=temp->next;
        }
    }
}//short code is below
int Queue_SLL::count()
{
    int i=0;
    node *temp=front;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}
Queue_SLL::~Queue_SLL()
{
    while(front!=NULL)
        Delete();
}
int main()
{
    Queue_SLL q1;
    q1.Delete();
    q1.Insert(34);
    q1.Insert(12);
    q1.Insert(57);
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.Insert(37);
     q1.Insert(34);
    q1.Insert(12);
    q1.Insert(57);
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.Insert(37);
    q1.view();  cout<<"count: "<<q1.count()<<endl;
}
/*
void Queue_SLL::view()
{
    node *temp=front;
    while(temp!=NULL)
    {
        cout<<"  "<<temp->item;
        temp=temp->next;
    }
}
*/
/*
void Queue_SLL::Insert(int data)
{
    node *t=new node;
    t->item=data;
    t->next=NULL;

    if(rear!=NULL) //that means front point 1st element of queue
      rear->next=t;
    if(front==NULL) //Or rear==NULL
       front=t;
    rear=t;
}
*/
/*
void Queue_SLL::Insert(int data)
{
    node *t=new node;
    t->item=data;
    t->next=NULL;

    if(rear!=NULL) //that means front point 1st element of queue
      rear->next=t;
    rear=t;
    if(front==NULL) //Or that means rear==NULL but due to execution of just above line rear will point new node
       front=t;
}
*/
