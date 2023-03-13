#include<iostream>
#include<stdio.h>
using namespace std;
class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;
public:
    Array();
    void CreateArray(int capacity);
    void AppendItem(int data);
    void InsertItem(int index,int data);
    int Count();
    int GetItem(int index);
    void DeleteItem(int index);
    void Edit(int index,int data);
    int SearchItem(int element); //Index will return of 1st occurrence of element in an array if it will found
    void View();
    ~Array();
};
Array::Array()
{
    capacity=0;
    lastindex=-1;
    ptr=NULL;
}
void Array::CreateArray(int capacity)
{
    if(ptr!=NULL)
        delete []ptr;
    this->capacity=capacity;
    lastindex=-1; //Imp
    ptr=new int[capacity]; //ptr=new int[this->capacity];
}
void Array::AppendItem(int data)
{
    if(lastindex+1==capacity)
        cout<<"Overflow";
    else
    {
        lastindex++; //Or ++lastindex;  ---------->This is better
        ptr[lastindex]=data;
    }
}
void Array::InsertItem(int index,int data)
{
    if(index<0 || index>lastindex+1)
        cout<<"Invalid Index";
    else if(lastindex+1==capacity)
        cout<<"Overflow";
    else
    {
        for(int i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastindex++;
    }
}
int Array::Count()
{
    return lastindex+1;
}
int Array::GetItem(int index)
{
    if(index>=0 && index<=lastindex)
       return ptr[index];
//When index is invalid then nothing will return
}
void Array::DeleteItem(int index)
{
    if(index<0 || index>lastindex)
        cout<<"Invalid Index Or Underflow";  //lastindex=-1 and index=0 then Underflow Situation
    else                                    //lastindex=3 and index=4 then Invalid Index Situation
    {
        for(int i=index;i<lastindex;i++) //Or i!=lastindex
            ptr[i]=ptr[i+1];
        lastindex--;
    }
}
void Array::Edit(int index,int data)
{
    if(index<0 || index>lastindex)
        cout<<"Invalid Index";
    else
       ptr[index]=data;
}
int Array::SearchItem(int element)  //Index is returning
{
    if(lastindex>-1) //Or lastindex>=0
        for(int i=0;i<=lastindex;i++)
           if(ptr[i]==element)
               return i;
    return -1;
}
void Array::View()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<"  ";
}
Array::~Array()
{
    delete []ptr;
}
