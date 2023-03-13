#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class Hashing  //5 digits key Or roll no.
{
private:
    struct node
    {
        int Fill;
        int key;
        string name; //record which we want to store in the array
        node *ptr; //Don't forget to write * symbol
    };
    node a[100];
protected:
    int HashFunction(int key);
public:
    Hashing();
    void insertitem(int key,string name);
    node searchitem(int key);
    ~Hashing();
};
int Hashing::HashFunction(int key)
{
    return key%100;
}
Hashing::Hashing()
{
    for(int i=0;i<100;i++)
    {
        a[i].ptr=NULL;
        a[i].key=-1;
        a[i].Fill=1; //Empty
    }
}
void Hashing::insertitem(int key,string name)
{
    int address=HashFunction(key);

    if(a[address].Fill)
    {
        a[address].key=key;
        a[address].name=name;
        a[address].Fill=0;
    }
    else
    {
        node *temp=a[address];
        while(temp.ptr!=NULL)
            temp=temp.ptr;
        temp.ptr=new node;
        temp.ptr->key=key;
        temp.ptr->name=name;
        temp.ptr->ptr=NULL;  //No need of fill to initialize with -1
    }
}
node Hashing::searchitem(int key)
{
    int address=HashFunction(key);

    node *temp=a[address];
    while(temp!=NULL)
    {
        if(temp.key==key)
            return temp;
        temp=temp->ptr;
    }

}
/*
        while(temp!=NULL)
            temp=temp->ptr;



        a[address].ptr=new node;
        a[address].ptr->key=key;
        a[address].ptr->name=name;
        a[address].ptr->Fill=0;
        a[address].ptr->ptr=NULL;
    }

    */
