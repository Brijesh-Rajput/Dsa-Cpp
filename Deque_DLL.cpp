#include<iostream>
#include<stdio.h>
using namespace std;
class Deque_DLL
{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;
    };
    node *front;
    node *rear;
public:
    Deque_DLL();
    void insertfront(int data);
    void Deletefront();
    void insertrear(int data);
    void Deleterear();
    void view();
    int count();
    ~Deque_DLL();
};
Deque_DLL::Deque_DLL()
{
    front=NULL;
    rear=NULL;
}
void Deque_DLL::insertfront(int data)
{
    node *t=new node;
    t->prev=NULL;
    t->item=data;
    t->next=front;

    if(front==NULL)
       rear=t;
    else
        front->prev=t;
    front=t;
}
void Deque_DLL::Deletefront()   //sort code is below
{
    if(front==NULL)
        cout<<"Underflow\n";
    else if(front==rear)
    {
        delete front; //delete rear;
        front=NULL;
        rear=NULL;
    }
    else  //that means at least there are 2 elements in the queue
    {
        node *temp=front;
        front->next->prev=front->prev; //Or front->next->prev=NULL;
        front=front->next;
        delete temp;
    }
}
void Deque_DLL::insertrear(int data)
{
    node *t=new node;
    t->prev=rear;
    t->item=data;
    t->next=NULL;

    if(rear==NULL)  //that means front also contain NULL
        front=t;
    else
        rear->next=t;
    rear=t;
}
void Deque_DLL::Deleterear()  //sort code is below
{
    if(rear==NULL)  //Or that means front==NULL;
        cout<<"Underflow\n";
    else if(rear==front)
    {
        delete rear; //Or delete front;
        rear=NULL;
        front=NULL;  //how to assign value in two variable ek saath
    }
    else
    {
        node *temp=rear;
        rear->prev->next=rear->next; //rear->prev->next=NULL;
        rear=rear->prev;
        delete temp;
    }
}
void Deque_DLL::view()
{
    node *t=front;
    while(t!=NULL)
    {
        cout<<t->item<<"  ";
        t=t->next;
    }
    cout<<endl;
}
int Deque_DLL::count()
{
    int i=0;
    node *t=front;
    while(t!=NULL)
    {
        i++;
        t=t->next;
    }
    return i;
}
Deque_DLL::~Deque_DLL()
{
    while(rear)
        Deleterear(); //Or Deletefront();  //both function takes same time
}
int main()
{
    Deque_DLL d1;
    d1.Deletefront();
    d1.insertfront(56);
    d1.insertfront(27);
    d1.insertrear(7);
    d1.insertrear(67);
    d1.insertfront(56);
    d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deletefront();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deleterear();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertrear(568);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertfront(256);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertfront(264);
    d1.insertrear(5);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deletefront();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deleterear();
    d1.Deleterear();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deletefront();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
}
/*
void Deque_DLL::Deleterear()  //sort code is below
{
    if(rear==NULL)  //Or that means front==NULL;
        cout<<"Underflow\n";
    else if(rear==front)
    {
        delete rear; //Or delete front;
        rear=NULL;
        front=NULL;  //how to assign value in two variable ek saath
    }
    else
    {
        node *temp=rear;
        if(rear==front)
        {
            front=NULL;
            rear=NULL;
        }
        else
        {
            rear->prev->next=rear->next; //rear->prev->next=NULL;
            rear=rear->prev;
        }
        delete temp;
    }
}
*/
/*
void Deque_DLL::Deletefront()
{
    if(front==NULL)
        cout<<"Underflow\n";
    else  //Deletion is possible
    {
        node *temp=front;
        if(front==rear)
        {
            front=NULL;
            rear=NULL;
        }
        else
        {
            front->next->prev=front->prev; //Or front->next->prev=NULL;
            front=front->next;
        }
        delete temp;
    }
}
*/
/*
Deque_DLL::~Deque_DLL()
{
    while(rear)
        Deletefront();
}
*/
/*
Deque_DLL::~Deque_DLL()
{
    while(front)
        Deletefront();
}
*/
/*
void Deque_DLL::Insertrear(int data)
{
    node *t=new node;
    t->prev=rear;
    t->item=data;
    if(rear==NULL)
        t->next=NULL;
    else
        t->next=rear->next;  //t->next=NULL;

    if(rear==NULL)
        front=NULL;
    else
        rear->next=t;
    rear=t;
}
*/
/*
void Deque_DLL::Insertfront(int data)
{
    node *t=new node;
    t->prev=NULL;
    t->item=data;
    t->next=front;

    if(front!=NULL)
       front->prev=t;
    if(rear==NULL)
       rear=t;
    front=t;
}
*/
