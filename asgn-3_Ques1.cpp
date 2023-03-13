//Dynamic Array
#include<iostream>
#include<conio.h>
using namespace std;
class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;
protected:
    void doubleArray();
    void HalfArray();
public:
    Array();
    void createArray(int cap);//Can i write this-->void create Array(int) ?
    void append(int data);
    void insert(int index,int data);
    void del(int index);
    int search(int data);
    int getData(int index);
    int count();
    void edit(int index,int newdata);
    void view();
    ~Array();
};
Array::Array()
{
    capacity=0;//Don't forget
    lastIndex=-1;
    ptr=NULL;
}
void Array::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[cap];
}
void Array::append(int data)
{
    if(lastIndex+1==capacity)
        doubleArray();
    ++lastIndex;//Or me:- lastIndex++
    ptr[lastIndex]=data;
}
void Array::insert(int index,int data)
{
    int i;
    if(index<0 || index>lastIndex+1)
        cout<<"\nInvalid Index";
    else
    {
      if(lastIndex+1==capacity)
        doubleArray();
      for(i=lastIndex;i>=index;i--)
        ptr[i+1]=ptr[i];
      ptr[index]=data;
      lastIndex++;
    }
}
void Array::doubleArray()
{
    int *ptr1;
    ptr1=new int[2*capacity];
    for(int i=0;i<capacity;i++)//Or i<=lastIndex
        ptr1[i]=ptr[i];
    capacity=2*capacity;//Or capacity*=2; //Don't forget this
    delete []ptr;
    ptr=ptr1;
    delete []ptr1;
}
void Array::HalfArray()
{
    int *ptr1;
    ptr1=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)//Or i<capacity/2
        ptr1[i]=ptr[i];
    capacity=capacity/2;//Or capacity/=2;
    delete []ptr;
    ptr=ptr1;
    delete []ptr1;
}
void Array::del(int index)
{
    int i;
    if(index<0 || index>lastIndex)
        cout<<"\nInvlid Index Or Underflow";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    if(lastIndex==capacity/2-1)
        HalfArray();
}
int Array::search(int data)
{
    for(int i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
         return i;
    return -1;
}
int Array::getData(int index)
{
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index";
    else
        return ptr[index];
}
int Array::count()
{
    return lastIndex+1;
}
void Array::edit(int index,int newdata)
{
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index";
    else
        ptr[index]=newdata;
}
void Array::view()
{
    for(int i=0;i<=lastIndex;i++)
        cout<<ptr[i]<<"  ";
}
Array::~Array()
{
   delete []ptr;
}
