//using array
#include<iostream>
#include<stdio.h>
using namespace std;
class Queue_Array_insert_restrict
{
private:
    int capacity;
    int *ptr;
    int front,rear;
public:
    Queue_Array_insert_restrict();
    void CreateArray(int capacity);
    //void insertfront(int data);
    void Deletefront();
    void insertrear(int data);
    void Deleterear();
    void view();
    int count();
    ~Queue_Array_insert_restrict();
};
Queue_Array_insert_restrict::Queue_Array_insert_restrict()
{
    ptr=NULL;
    capacity=0;
    front=-1;
    rear=-1;
}
void Queue_Array_insert_restrict::CreateArray(int capacity)
{
    if(ptr!=NULL)
        delete ptr;
    this->capacity=capacity;
    front=-1;
    rear=-1;
    ptr=new int[capacity];  //Or ptr=new int[this->capacity];
}
/*
void Deque_Array::insertfront(int data)
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(rear+1==front || rear==capacity-1 && front==0)
        cout<<"Overflow\n";
    else if(front==-1)
    {
        front=0;
        rear=0;
        ptr[front]=data;
    }
    else if(front==0)
    {
        front=capacity-1;
        ptr[front]=data;
    }
    else
    {
        front--;
        ptr[front]=data;
    }
}
*/
void Queue_Array_insert_restrict::Deletefront()
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(front==-1) //when front==rear then also this if will not execute
        cout<<"Underflow\n";
    else if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
void Queue_Array_insert_restrict::insertrear(int data)
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(rear+1==front || rear==capacity-1 && front==0)
        cout<<"Overflow\n";
    else if(rear==-1) //Or front==-1
    {
        rear++;  //Or rear=0;
        front++; //Or front=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1) //obviously here front is not equal to zero b'coz if this happen then Overflow situation will happen
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
void Queue_Array_insert_restrict::Deleterear()
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(rear==-1)  //that means front is also equal to -1
        cout<<"Underflow\n";
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
        rear=capacity-1;
    else
        rear--;
}
void Queue_Array_insert_restrict::view()
{
    if(ptr==NULL)
        cout<<"Invalid Operation";
    else if(front==-1)
        cout<<"Empty Queue";
    else
    { //for both wen rear<=front and rear>front
        cout<<"Queue:";
        int i=front;
        do
        {
            if(i==capacity)
                i=0;
            cout<<"  "<<i<<"-"<<ptr[i];
            i++;
        }while(i!=rear+1);
    }
    cout<<endl;
}
int Queue_Array_insert_restrict::count()
{
    int i=-1;
    if(ptr==NULL)
        cout<<"Invalid Operation";
    else if(front==-1)
        cout<<"Empty Queue";
    else
    {
        int j=front;
        do
        {
            if(j==capacity)
                j=0;
            j++;
            i++;
        }while(j!=rear+1);
    }
    return i+1;
}
Queue_Array_insert_restrict::~Queue_Array_insert_restrict()
{
    delete ptr;
}
int main()
{
    Queue_Array_insert_restrict d1;
    d1.CreateArray(5);
    d1.Deleterear();
    d1.insertrear(56);
    d1.insertrear(27);
    d1.insertrear(7);
    d1.insertrear(67);
    d1.insertrear(56);
    d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deletefront();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deleterear();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertrear(568);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertrear(256);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertrear(264);
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
