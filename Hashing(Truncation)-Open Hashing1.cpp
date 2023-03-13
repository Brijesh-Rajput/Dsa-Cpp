#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class Hashing
{
private:
    struct node
    {
        int key;
        string name; //record which we want to store in the array
        node *ptr; //Don't forget to write * symbol
    };
    node* a[100];
protected:
    int HashFunction(int key);
public:
    Hashing();
    void insertitem(int key,string name);
    node searchitem(int key);
    ~Hashing();
};
Hashing::Hashing()
{
    for(int i=0;i<100;i++)
    {
        a[i].ptr=NULL;
        a[i].key=-1;
    }
}
void Hashing::insertitem(int key,string name)
{
    int address=HashFunction(key);

    if(ptr==NULL)
    {
        a[address].key=key;
        a[address].name=name;
    }
}


