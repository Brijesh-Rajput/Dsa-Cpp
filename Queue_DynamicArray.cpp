#include<iostream>
#include<stdio.h>
using namespace std;
class Queue_Array
{
private:
    int *ptr;
    int capacity;
    int rear,front;
protected:
    void DoubleArray();
    void HalfArray();
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
void Queue_Array::DoubleArray()
{
    int *p=new int[capacity*2];
    for(int i=0;i<=rear;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
    capacity*=2;
}
void Queue_Array::HalfArray()
{
    int *p=new int[capacity/2];
    for(int i=0;i<=rear;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
    capacity/=2;
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
        DoubleArray();
    rear++;
    ptr[rear]=data;
    if(front==-1)
        ++front;
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
        if(rear==capacity/2-1 && capacity>1)  //me:- rear<=capacity/2-1 && capacity>1
            HalfArray();
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
    q1.InsertItem(452);
    q1.InsertItem(754);
    q1.InsertItem(12);
    q1.InsertItem(57);
    q1.InsertItem(67);
    q1.InsertItem(87);
    q1.InsertItem(27);
    q1.view();
    q1.DeleteItem();
    q1.view();
    q1.DeleteItem();
    q1.InsertItem(37);
    q1.view();
    q1.DeleteItem();
    q1.DeleteItem();
    q1.view();
}
