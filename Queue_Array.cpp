#include<iostream>
#include<stdio.h>
using namespace std;
class Queue_Array
{
private:
    int *ptr;
    int capacity;
    int rear,front;
public:
    Queue_Array();
    void CreateQueue(int capacity);
    void InsertItem(int data);
    void DeleteItem();
    void view();
    int count();
    ~Queue_Array();
};
Queue_Array::Queue_Array()
{
    ptr=NULL;
    capacity=0;
    rear=-1;
    front=-1;
}
void Queue_Array::CreateQueue(int capacity)
{
    if(ptr!=NULL)
        delete ptr;
    else
    {
        this->capacity=capacity;
        rear=-1;
        front=-1;
        ptr=new int[capacity];  //Or ptr=new int[this->capacity];
    }
}
void Queue_Array::InsertItem(int data)
{
    if(rear+1==capacity)
        cout<<"Overflow"<<endl;
    else
    {
        rear++;
        ptr[rear]=data;
        if(front==-1)
            ++front;
    }
}
void Queue_Array::DeleteItem()
{
    if(rear==-1) //Or if(front==-1)
        cout<<"Underflow"<<endl;
    else
    {
       for(int i=0;i<rear;i++)
        ptr[i]=ptr[i+1];
        --rear;
        if(rear==-1)
            --front;
    }
}
void Queue_Array::view()
{
    for(int i=0;i<=rear;i++)
        cout<<ptr[i]<<"  ";
    cout<<"\n";
}//IF (rear=-1) then cout<<"Queue i sempty";  Or //if(front==-1)
int Queue_Array::count()
{
    return rear+1;
}
Queue_Array::~Queue_Array()
{
    delete ptr;
}
int main()
{
    Queue_Array q1;
    q1.CreateQueue(5);
    q1.DeleteItem();
    q1.InsertItem(34);
    q1.InsertItem(12);
    q1.InsertItem(57);
    q1.view();
    q1.DeleteItem();
    q1.view();
    q1.DeleteItem();
    q1.InsertItem(37);
    q1.view();
}
/*
//DR your code before executing Or run
//Don't do this --> here i have applied wrong left shifting
void Queue_Array::DeleteItem()
{
    if(rear==-1) //Or if(front==-1)
        cout<<"Underflow"<<endl;
    else
    {
        for(int i=rear-1;i>=0;i--)
             ptr[i]=ptr[i+1];
        --rear;
        if(rear==-1)
            --front;
    }
}
*/
