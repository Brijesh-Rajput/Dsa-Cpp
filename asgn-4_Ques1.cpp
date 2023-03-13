#include<iostream>
#include<conio.h>
using namespace std;
class LinkedList
{
private:
    struct node
    {
        int item;
        node* next;
    };
    node* start;
public:
    LinkedList();
    void insertAtFirst(int data);
    void insertAtLast(int data);
    void insertAfter(node *t,int data);//check whether address is valid or not acc. to me
    void deleteFirst();
    void deleteLast();
    void deleteNode(node *t);//check whether address is valid or not acc. to me
    void* search(int data);  //why return type is void here??? //Data type of node is node so return type should be node*
    ~LinkedList();
};
LinkedList::deleteLast()//2ND TIME
{
    if(start==NULL)
        cout<<"List is already Empty";
    else
    {
        node* t;
        t=start;
        if(t->Next!=NULL)
        {
            while(t->next->next!=NULL)
               t=t->next;
            delete t->next;
            t->next=NULL;
        }
        else
        {
            delete t;
            start=NULL;
        }
    }
}
/* wrong

LinkedList::insertAfter(node* temp,int data)//What happen if temp value is NULL or zero
{
    node* t;
    t=start;
    while(t->next!=NUll && t->next!=temp)
         t=t->next;
    if(t->next==NULL)
        cout<<"Invalid address of node";
    else
    {
        t=new node;
        t->next=data;
        t->next=temp->next;
        temp->next=t;
    }
}
*/
/* wrong
LinkedList::insertAfter(node*temp)//What happen if temp value is NULL or zero
{
    node* t;
    t=start;
    int i=0;
    while(t->next!=NUll && t->next!=temp && ++i)
    {
         t=t->next;
         i--;
    }
    if(i==0) //b'coz if any one of them is false from above 1st two condition then next condition will not be check so that means i will not increment
        cout<<"Invalid address of node";
    else
    {

    }
}
*/
LinkedList::LinkedList()
{
    start=NULL;
}
void LinkedList::insertAtFirst(int data)
{
    if(start==NULL)
    {
       start=new node;
       start->item=data;//Or *start.item=data;
       start->next=NULL;
    }
    else
    {
        node* temp;
        temp=new node;
        temp->item=data;
        temp->next=start;
        start=temp;
    //  temp will automatically release b'coz its a static memory
    //  And don't release the memory which is made by temp pointer using dynamic b'coz both temp and start pointing to the same address
    }
}
void LinkedList::insertAtLast(int data)
{
    node *temp;
    temp=start;
    if(temp==NULL)
    {
       start=new node;
       temp=start;
    }
    else
    {
        while(1)
        {
            if(temp->next==NULL)
            {
                temp->next=new node;
                temp=temp->next;
                break;
            }
            else
                temp=temp->next;
        }
    }
    temp->item=data;
    temp->next=NULL;
}
void LinkedList::insertAfter(node *t,int data) //what happen if i write q instead of t b'coz in declaration and defination of function difference will come in pointer variable name
{
//To check whether Given Address of node is valid or Not
    node *temp2;
    temp2=start;
    int i=0;
    while(temp2!=NULL)
    {
        if(temp2->next!=t)
            temp2=temp2->next;
        else
            {
                i++;//address will be only one so, no need to check further in loop
                break;//That means Given address is valid address of any node
            }
    }
    if(i!=1)
        cout<<"InValid Address of node";
    else if(t->next==NULL)   //Or (*t).next==NULL
    {
        t->next=new node; //Or (*t).next=new node;
        t->next->item=data;// (*((*t).next)).item=data;
        t->next->next=NULL;
    }
    else
    {
        node *temp;
        temp=t->next;
        t->next=new node;
        t->next->item=data;
        t->next->next=temp;
    }
}
void LinkedList::deleteFirst()
{
    if(start==NULL)
        cout<<"List is already Empty";
    else
    {
        node *temp;
        temp=start;
        start=start->next;
        delete temp;
    }
}
void LinkedList::deleteLast()
{
    if(start==NULL)
        cout<<"List items are already Empty";
    else
    {
        node *temp;
        temp=start;
        while(1)
        {
            if(temp->next==NULL) //(*temp).next==NULL
            {
                delete temp;
                start=NULL;
                break;
            }
            else if(temp->next!=NULL && temp->next->next==NULL)
            {
                delete temp->next;
                temp->next=NULL;
                break;
            }
            else
                temp=temp->next;
        }
    }
}
void LinkedList::deleteNode(node *t)//Acc. to me at address NULL there is no node b'coz when pointer contains NULL that means zero0---->That means pointer is not pointing anything
{//This function code is also valid when given address is of last Nodes

    node *temp2;
    temp2=start;
    int i=0;
    while(temp2!=NULL)
    {
        if(temp2->next!=t)
            temp2=temp2->next;
        else
            {
                i++;//address will be only one so, no need to check further in loop
                break;//That means Given address is valid address of any node
            }
    }
  if(i!=1)
        cout<<"InValid Address of node";
  else if(start==NULL)
    cout<<"List is already Empty";
  else
  {
    node *temp,*temp1;//Don't write this --> or Don't forget to write indirection operator like---> node *temp,temp1; //if i did this then i get this error :- no match for 'operator=' (operand types are 'LinkedList::node' and 'LinkedList::node*')
    temp=t->next;
    temp1=start;
    while(1)
    {
        if(temp1->next==t)
        {
            delete temp1->next;
            temp1->next=temp;
            break;
        }
        temp1=temp1->next;
    }
  }
}
void* LinkedList::search(int data)   //DON'T Write This --------->   void* LinkedList::search(int data);
{
    node *temp;
    temp=start;
    while(1)
    {
        if(temp->next==NULL)
            break;
        if(temp->item==data)
            return temp;
        temp=temp->next;
    }
    return -1;//That means data is not present in a list
//above stmt gives me an Error :- invalid conversion from 'int' to 'void' [-fpermissive] //But Why??????????????????????????????????????????
}
LinkedList::~LinkedList()
{
    while(start!=NULL)
       deleteLast();
}
/* wrong :- something is missing
void LinkedList::deleteNode(node *t)  //wrong when there is no items in a list
{//Suppose given address is valid && address is not NULL
//This is also valid when given address is of last Nodes
    node *temp,*temp1;//Don't write this or Don't forget to write indirection operator like---> node *temp,temp1; //if i did this then i get this error :- no match for 'operator=' (operand types are 'LinkedList::node' and 'LinkedList::node*')
    temp=t->next;
    temp1=start;
    while(1)
    {
        if(temp1->next==t)
        {
            delete temp1->next;
            temp1->next=temp;
            break;
        }
        temp1=temp1->next;
    }
}
*/
/* wrong:- something is missing
void LinkedList::insertAfter(node *t,int data) //what happen if i write q instead of t b'coz in declaration and defination of function difference will come in pointer variable name
{//suppose given address is valid  AND  //suppose given address is not NULL
    if(t->next==NULL)   //Or (*t).next==NULL
    {
        t->next=new node; //Or (*t).next=new node;
        t->next->item=data;// (*((*t).next)).item=data;
        t->next->next=NULL;
    }
    else
    {
        node *temp;
        temp=t->next;
        t->next=new node;
        t->next->item=data;
        t->next->next=temp;
    }
}
*/
/*
LinkedList::~LinkedList()
{
    if(start!=NULL)
       deleteLast();//only last node will delete b'coz there is no loop
//No need to delete start
//B'coz destructor is generally used to delete dynamically memory so that, memory leakage doesn't happen
}
*/
/*wrong
LinkedList::~LinkedList() //Imp
{//if you delete memory whose address is in start only then memory will leak ,so firstly delete all nodes first then delete start pointer
//if we delete only memory whose address is store in start pointer variable then we lost the address of all connected nodes
    delete start;
}
*/
/*right but doubt ----see the last question
void* LinkedList::search(int data);
{
    node *temp;
    temp=start;
    while(1)
    {
        if(temp->next==NULL)
            break;
        else //No need to write this
        {
            if(temp->item==data)
                return temp;
            temp=temp->next;
        }
    }
    return -1;//B'coz address can't be negative. Value of Address start from 0 and upto something 2665 depend upon computer architecture
  //  return 0;//when 0 is return as a address that means pointer doesn't point anything ptr contains NULL
//I have a Question that can i write return 0 instead of return -1 ????????????????;
}
*/
/*wrong:- b'coz user can enter non-valid address of node
void LinkedList::insertAfter(node *t,int data) //what happen if i write q instead of t b'coz in declaration and defination of function difference will come in pointer variable name
{
    if(t->next==NULL)   //Or (*t).next==NULL
    {
        t->next=new node; //Or (*t).next=new node;
        t->next->item=data;// (*((*t).next)).item=data;
        t->next->next=NULL;
    }
    else
    {
        node *temp;
        temp=t->next;
        t->next=new node;
        t->next->item=data;
        t->next->next=temp;
    }
}
*/
/* wrong
void LinkedList::deleteLast()
{
    if(start==NULL)
        cout<<"List items are already Empty";
    else
    {
        node *temp;
        temp=start;
        while(1)
        {
            if(temp->next==NULL) //(*temp).next==NULL
            {
                delete temp;//We deleted the last node whose address was store in temp pointer variable and obviously this last node contains NULL in next pointer variable
//But Now also, next pointer variable of 2nd last node contains the address of last node which was deleted so, it contains garbage value acc. to us .
//Now, our task to store NULL in next pointer variable of 2nd last node
        //    temp=NULL; <----This is also wrong. 1st of all, we want to store NULL in start pointer variable not in temp pointer variable
                break;
            }
            else
                temp=temp->next;
        }
    }
}
*/
/* wrong :-//But when there is only one items in a list then this function will become wrong
void LinkedList::deleteLast()
{
    if(start==NULL)
        cout<<"List items are already Empty";
    else
    {
        node *temp;
        temp=start;
        while(1)
        {
            if(temp->next->next==NULL)
            {
                delete temp->next;
                temp->next=NULL;//we can't write this Line Before above line b'coz if we do this then, address of last node will lost and we can't delete the memory of last node,so its memory leakage will happen here
                break;
            }
            else
                temp=temp->next;
        }
    }
}
*/
/* wronG Acc. to me
void LinkedList::deleteFirst()
{
    if(start==NULL)
        cout<<"List is already Empty";
    else
    {
        node *temp;
        temp=start;
        delete temp;//This step is Blunder b'coz by this memory of 1st node is release by delete keyword and address of all nodes after that we lost so we can't access any nodes after that AND Memory leak will happen there
        start=start->next;//B'coz of above wrong step this line will show an error acc. to me BUT IT's Not showing An EError Why ???
    }
}
*/
/* wrong
void LinkedList::deleteFirst()
{
    if(start==NULL)
        cout<<"List is already Empty";
    else
    {
        start=start->next;
        //In this Memory leak will happen
    }
}
*/
/*  right
void LinkedList::insertAtLast(int data)
{
    if(start==NULL)
    {
        start=new node;
        start->item=data;//If LinkedList was structure instead of class in c then we have to write like this-->l1.start->item=data; where l1 is a variable of Linkedlist Data type
        start->next=NULL;
    }
    else
    {
        node *temp;
        temp=start;
        while(temp!=NULL)
        {
            if(temp->next==NULL)
            {
                temp->next=new node;
                temp->next->item=data;
                temp->next->next=NULL;
                break;//Its necessary
            }
            else
               temp=(*temp).next;//Or temp=temp->next;
// temp=*temp.next; //Or temp=temp->next      <-----------------This is Error But Why?? Acc. to Cindepth book and my concept which i learnt from it,  its right
//Error:-request for member 'next' in 'temp',which is of pointer type 'LinkedList::node*' (maybe you meant to use '->' ?)
//I got this Error b'coz dot operator has highest priority compare to * operator
        }
    }
}
*/
/*  wrong
void LinkedList::insertAtLast(int data)
{
    if(start==NULL)
    {
        start=new node;
        start->item=data;//If LinkedList was structure instead of class in c then we have to write like this-->l1.start->item=data; where l1 is a variable of Linkedlist Data type
        start->next=NULL;
    }
    else
    {
        node *temp;
        temp=start;
        while(temp!=NULL)
        {
            temp=*temp.next; //Or temp=temp->next
            if(temp==Null)
            {
                temp=new node;
                temp->next->item=data;
                temp->next->next=NULL;
                break;
            }
        }
    }
}
*/
/*right but in last else body something is wrong
void LinkedList::insertAtLast(int data)
{
    if(start==NULL)
    {
        start=new node;
        start->item=data;//If LinkedList was structure instead of class in c then we have to write like this-->l1.start->item=data; where l1 is a variable of Linkedlist Data type
        start->next=NULL;
    }
    else
    {
        node *temp;
        temp=start;
        while(temp!=NULL)
        {
            if(temp->next==Null)
            {
                temp->next=new node;
                temp->next->item=data;
                temp->next->next=NULL;
                break;
            }
            else
              temp=*temp.next; //Or temp=temp->next
        }
    }
}
*/
/*
void LinkedList::insertAtFirst(int data)
{
    if(start==NULL)
    {
       start=new node[1];
       start->item=data;//Or *start.item=data;  <----This is Wrong //B'coz start[0]->item=data;
       start->next=NULL;
    }
    else
    {
        node* temp;
        temp=new node[1];
        temp->item=data;
        temp->next=start;
        start=temp;
    }
}
*/
/*
LinkedList::LinkedList()
{
    start=NULL;
    node::node()
    {
        next=NULL;
    }
}
*/
