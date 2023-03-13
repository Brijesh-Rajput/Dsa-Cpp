#include<iostream>
#include<stdio.h>
using namespace std;
class Queue_CDLL
{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;
    };
    node *rear;
    node *front;
public:
    Queue_CDLL();
    void Insert(int data);
    void Delete();
    void view();
    void count();
    ~Queue_CDLL();
};
Queue_CDLL::Queue_CDLL()
{
    rear=NULL;
    front=NULL;
}
void Queue_CDLL::Insert(int data)
{
    node *t=new node;
    t->prev=rear;
    t->item=data;
    t->next=NULL:

    if(rear!=NULL)
       rear->next=t;
    if(front==NULL)  //Or rear==NULL
        front=t;
    rear=t;
}
void Queue_CDLL::Delete()
{
    if(front==NULL)
        cout<<"Underflow";
    else
    {
        if(front==rear)
        {
           delete front;
           front=NULL;
           rear=NULL;
        }
        else if(front->next==rear)
        {
            rear->prev=NULL;
            delete front;
        }
        else
        {
            front->next->prev=NULL;
        }
    }
}
