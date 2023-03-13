//HalfArray is important -->when capacity is 1 and we want to delete an item of index 0(lastindex==0)
#include<iostream>
#include<stdio.h>
using namespace std;
class DynamicArray
{
private:
    int capacity;
    int lastindex;
    int *ptr;
protected:
    void DoubleArray();
    void HalfArray();
public:
    DynamicArray();
    void CreateArray(int capacity);
    void AppendItem(int data);
    void InsertItem(int index,int data);
    int Count();
    int GetItem(int index);
    void DeleteItem(int index);
    void Edit(int index,int data);
    int SearchItem(int element); //Index will return of 1st occurrence of element in an array if it will found
    void View();
    ~DynamicArray();
};
void DynamicArray::DoubleArray()
{
    int *p=new int[2*capacity];
    capacity*=2;
    for(int i=0;i<=lastindex;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
}
void DynamicArray::HalfArray()
{
    int *p=new int[capacity/2];  //Acc. to me :- int *p=new int[capacity/=2]; //Imp
    capacity/=2;
    for(int i=0;i<=lastindex;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
}
DynamicArray::DynamicArray()
{
    capacity=0;
    lastindex=-1;
    ptr=NULL;
}
void DynamicArray::CreateArray(int capacity)
{
    if(ptr!=NULL)
        delete []ptr;
    this->capacity=capacity;
    lastindex=-1; //Imp
    ptr=new int[capacity]; //ptr=new int[this->capacity];
}
void DynamicArray::AppendItem(int data)
{
    if(lastindex+1==capacity)
        DoubleArray();
    lastindex++; //Or ++lastindex;  ---------->This is better
    ptr[lastindex]=data;
}
void DynamicArray::InsertItem(int index,int data)
{
    if(index<0 || index>lastindex+1)
        cout<<"Invalid Index";
    else
    {
        if(lastindex+1==capacity)
           DoubleArray();
        for(int i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastindex++;
    }
}
int DynamicArray::Count()
{
    return lastindex+1;
}
int DynamicArray::GetItem(int index)
{
    if(index>=0 && index<=lastindex)
       return ptr[index];
//When index is invalid then nothing will return
}
void DynamicArray::DeleteItem(int index)
{
    if(index<0 || index>lastindex)
        cout<<"Invalid Index Or Underflow"; //lastindex=-1 and index=0 then Underflow Situation
    else                                    //lastindex=3 and index=4 then Invalid Index Situation
    {
        for(int i=index;i<lastindex;i++) //Or i!=lastindex
            ptr[i]=ptr[i+1];
        lastindex--;
        if(lastindex<=capacity/2-1 && capacity>1)   //Condition very Imp  //Sir Condition
           HalfArray();                               //My condition is better Acc. to me
    }                                                  //lastindex<=capacity/2-1
}
void DynamicArray::Edit(int index,int data)
{
    if(index<0 || index>lastindex)
        cout<<"Invalid Index";
    else
       ptr[index]=data;
}
int DynamicArray::SearchItem(int element)  //Index is returning
{
    if(lastindex>-1) //Or lastindex>=0
        for(int i=0;i<=lastindex;i++)
           if(ptr[i]==element)
               return i;
    return -1;
}
void DynamicArray::View()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<"  ";
}
DynamicArray::~DynamicArray()
{
    delete []ptr;
}
