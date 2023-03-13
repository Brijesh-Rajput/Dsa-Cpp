
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class BST //all elements are distinct
{
public:
    struct node
    {
        node *lchild;
        int item;
        node *rchild;
    };
    node *root;
private:
        void Deletion_no_child(node *parptr,node *ptr,int data);
        void Deletion_one_child(node *parptr,node *ptr,int data);
        void Deletion_two_child(node*ptr);
         void pre(node *temp);
public:
    BST();
    void insertitem(int data);
   // void preorderTraversal();
    void InorderTraversal();
  //  void postorderTraversal();
  //  ~BST();

    void Delete(int data);
};
BST::BST()
{
    root=NULL;
}
void BST::insertitem(int data)
{ //we can use here two pointer for traversing
    node *temp=root;

    if(temp==NULL)  //Or Root==NULL
    {
        root=new node;
        root->item=data;
        root->lchild=NULL;
        root->rchild=NULL;
    }
    else
    {
        int flag=-1;
        while(1)
        {
            if(temp->item>data)
            {
                if(temp->lchild==NULL)
                {
                    flag=1;
                     break;
                }
                temp=temp->lchild;
            }
            else //child can equal to or greater than node
            {
                if(temp->rchild==NULL)
                {
                    flag=0;
                     break;
                }
                temp=temp->rchild;
            }
        }
        if(flag)
        {
            temp->lchild=new node;
            temp->lchild->item=data;
            temp->lchild->lchild=NULL;
            temp->lchild->rchild=NULL;
        }
        else
        {
            temp->rchild=new node;
            temp->rchild->item=data;
            temp->rchild->lchild=NULL;
            temp->rchild->rchild=NULL;
        }
    }
}
void BST::InorderTraversal()
{
//   lchild
//   node
//   rchild

    node *temp=root;
    if(temp!=NULL)
        pre(temp);
    cout<<endl;
}
void BST::pre(node *temp)
{
    if(temp->lchild)
    {
        pre(temp->lchild);
        cout<<temp->item<<" ";
        if(temp->rchild!=NULL)
            pre(temp->rchild);
    }
    else
    {
        cout<<temp->item<<" ";
        if(temp->rchild!=NULL)
            pre(temp->rchild);
    }

}
void BST::Delete(int data)  //not for the duplicate value cases
{
    node *ptr,*parptr;  //NOt node* ptr,parptr;
    ptr=root;
    parptr=NULL;

    while(ptr)
    {
        if(ptr->item>data)
        {
            parptr=ptr;
            ptr=ptr->lchild;
        }
        else if(ptr->item<data)
        {
            parptr=ptr;
            ptr=ptr->rchild;
        }
        else //ptr->item==data
            break;
    }

    if(ptr==NULL)
        cout<<"Data Not found\n";
    else if(ptr->lchild==NULL &&  ptr->rchild!=NULL || ptr->rchild==NULL && ptr->lchild!=NULL)
        Deletion_one_child(parptr,ptr,data);
    else if(ptr->lchild==NULL && ptr->rchild==NULL)
        Deletion_no_child(parptr,ptr,data);
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
        Deletion_two_child(ptr);

    /*
    Deletion_one_child();
    Deletion_Two_child();
    Deletion_zero_child();
    */
}
void BST::Deletion_one_child(node *parptr,node *ptr,int data) //But how this function can access parptr ????
{
    if(ptr==root)  //Here parptr==NULL thats why  we have to change in rot node
    {
        if(ptr->lchild!=NULL)
            root=ptr->lchild;
        else
            root=ptr->rchild;
        delete ptr;
    }
    else
    {
        if(ptr->lchild!=NULL)
        {
            if(parptr->item>data)
                parptr->lchild=ptr->lchild;
            else
                parptr->rchild=ptr->lchild;
            delete ptr;
        }
        else  //that means ptr->lchild==NULL and ptr->rchild!=NULL
        {
            if(parptr->item>data)
                parptr->lchild=ptr->rchild;
            else
                parptr->rchild=ptr->rchild;
            delete ptr;
        }
    }
}
void BST::Deletion_no_child(node *parptr,node*ptr,int data)
{
    if(ptr==root)  //obviously parptr==NULL     //NOTICE:- Root is not defined in this scope but its a pointer variable in the class so, it is not giving any error
        root=NULL;
    else if(parptr->item>data)
        parptr->lchild=NULL;
    else
        parptr->rchild=NULL;
    delete ptr;
}
void BST::Deletion_two_child(node *ptr) //here traversing is required to find the successor and predecor
{//predecsor
    //here ptr can be anything , it can be root node
        node*parpoint=ptr;
        node *point=ptr->lchild; //point=parpoint->lchild;
        while(point->rchild!=NULL)
        {
            parpoint=point;
            point=point->rchild;
        }
        ptr->item=point->item;
        //for delete this point pointing that node there is only two possibility
        //1st no node or one left child  node //But there is no one right child node
        if(point->lchild==NULL)
        {
            if(parpoint->lchild==point)
                parpoint->lchild=NULL;
            else
                parpoint->rchild=NULL;
            delete point;
        }
        else //point->lchild!=NULL;
        {
            if(parpoint->lchild==point)
                parpoint->lchild=point->lchild;
            else
                parpoint->rchild=point->lchild;
            delete point;
        }
 }
int main()
{
    BST b1;
    b1.insertitem(98);
    b1.insertitem(60);
    b1.insertitem(120);
    b1.insertitem(50);
    b1.insertitem(65);
    b1.insertitem(110);
    b1.insertitem(140);
    b1.insertitem(40);
    b1.insertitem(55);
    b1.insertitem(63);
    b1.insertitem(70);
    b1.insertitem(130);
    b1.insertitem(150);
    b1.insertitem(53);
    b1.insertitem(58);
    b1.insertitem(68);
    b1.insertitem(75);
    b1.insertitem(135);
    b1.insertitem(145);
    b1.insertitem(160);
    b1.insertitem(57);
    b1.insertitem(73);
    b1.insertitem(78);
    b1.insertitem(142);
    b1.insertitem(155);
    b1.InorderTraversal();
    b1.Delete(111);
    b1.InorderTraversal();
}
/*
node* pre(node *temp)
{
    if(temp->lchild==NULL)
    {
        cout<<temp->item<<" ";
        if(temp->rchild!=NULL)
            pre(temp->rchild);
    }
    else
    {
        temp=temp->lchild;
        pre(temp);
    }
}
*/
/*
node* pre(node *temp)
{
    if(temp->lchild==NULL)
    {

    }
    if(temp->lchild!=NULL)
        temp=temp->lchild;
    pre(temp);
}
*/
/*
void BST::InorderTraversal()
{
    lchild
    node
    rchild


    pre(temp)
    node *temp=root;

    if(temp->lchild!=NULL)
        temp=temp->lchild;

}
*/





/*
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class BST //all elements are distinct
{
public:
    struct node
    {
        node *lchild;
        int item;
        node *rchild;
    };
    node *root;
private:
        void Deletion_no_child(node *parptr,node *ptr,int data);
        void Deletion_one_child(node *parptr,node *ptr,int data);
        void Deletion_two_child(node*ptr);
         void pre(node *temp);
public:
    BST();
    void insertitem(int data);
   // void preorderTraversal();
    void InorderTraversal();
  //  void postorderTraversal();
  //  ~BST();

    void Delete(int data);
};
BST::BST()
{
    root=NULL;
}
void BST::insertitem(int data)
{ //we can use here two pointer for traversing
    node *temp=root;

    if(temp==NULL)  //Or Root==NULL
    {
        root=new node;
        root->item=data;
        root->lchild=NULL;
        root->rchild=NULL;
    }
    else
    {
        int flag=-1;
        while(1)
        {
            if(temp->item>data)
            {
                if(temp->lchild==NULL)
                {
                    flag=1;
                     break;
                }
                temp=temp->lchild;
            }
            else //child can equal to or greater than node
            {
                if(temp->rchild==NULL)
                {
                    flag=0;
                     break;
                }
                temp=temp->rchild;
            }
        }
        if(flag)
        {
            temp->lchild=new node;
            temp->lchild->item=data;
            temp->lchild->lchild=NULL;
            temp->lchild->rchild=NULL;
        }
        else
        {
            temp->rchild=new node;
            temp->rchild->item=data;
            temp->rchild->lchild=NULL;
            temp->rchild->rchild=NULL;
        }
    }
}
void BST::InorderTraversal()
{
//   lchild
//   node
//   rchild

    node *temp=root;
    if(temp!=NULL)
        pre(temp);
    cout<<endl;
}
void BST::pre(node *temp)
{
    if(temp->lchild==NULL)
    {
        cout<<temp->item<<" ";
        if(temp->rchild!=NULL)
            pre(temp->rchild);
    }
    else
    {
        pre(temp->lchild);
        cout<<temp->item<<" ";
        if(temp->rchild!=NULL)
            pre(temp->rchild);
    }
}
void BST::Delete(int data)
{
    node *ptr,*parptr;  //NOt node* ptr,parptr;
    ptr=root;
    parptr=NULL;

    while(1)
    {
        if(ptr->item>data)
        {
            parptr=ptr;
            ptr=ptr->lchild;
        }
        else if(ptr->item<data)
        {
            parptr=ptr;
            ptr=ptr->rchild;
        }
        else //ptr->item==data
        {
            break;
        }
    }

    if(ptr->lchild==NULL &&  ptr->rchild!=NULL || ptr->rchild==NULL && ptr->lchild!=NULL)
        Deletion_one_child(parptr,ptr,data);
    else if(ptr->lchild==NULL && ptr->rchild==NULL)
        Deletion_no_child(parptr,ptr,data);
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
        Deletion_two_child(ptr);


    /*
    Deletion_one_child();
    Deletion_Two_child();
    Deletion_zero_child();
    *

}
void BST::Deletion_one_child(node *parptr,node *ptr,int data) //But how this function can access parptr ????
{
    if(ptr==root)
    {
        if(ptr->lchild!=NULL)
            root=ptr->lchild;
        else
            root=ptr->rchild;
        delete ptr;
    }
    else
    {
        if(ptr->lchild!=NULL)
        {
            if(parptr->item>data)
                parptr->lchild=ptr->lchild;
            else
                parptr->rchild=ptr->lchild;
            delete ptr;
        }
        else
        {
            if(parptr->item>data)
                parptr->lchild=ptr->rchild;
            else
                parptr->rchild=ptr->rchild;
            delete ptr;
        }
    }
}
void BST::Deletion_no_child(node *parptr,node*ptr,int data)
{
    if(ptr==root)
    {
        root=NULL;
        delete ptr;
    }
    else
    {
        if(parptr->item>data)
            parptr->lchild=NULL;
        else
            parptr->rchild=NULL;
        delete ptr;
    }
}
void BST::Deletion_two_child(node *ptr) //here traversing is required to find the successor and predecor
{//predecsor
    //here ptr can be anything , it can be root node
        node*parpoint=ptr;
        node *point=ptr->lchild; //point=parpoint->lchild;
        while(point->rchild!=NULL)
        {
            parpoint=point;
            point=point->rchild;
        }
        ptr->item=point->item;
        //for delete this point pointing that node there is only two possibility
        //1st no node or one left child  node //But there is no one right child node
        if(point->lchild==NULL)
        {
            if(parpoint->lchild==point)
                parpoint->lchild=NULL;
            else
                parpoint->rchild=NULL;
            delete point;
        }
        else //point->lchild!=NULL;
        {
            if(parpoint->lchild==point)
                parpoint->lchild=point->lchild;
            else
                parpoint->rchild=point->lchild;
            delete point;
        }
 }
int main()
{
    BST b1;
    b1.insertitem(98);
    b1.insertitem(60);
    b1.insertitem(120);
    b1.insertitem(50);
    b1.insertitem(65);
    b1.insertitem(110);
    b1.insertitem(140);
    b1.insertitem(40);
    b1.insertitem(55);
    b1.insertitem(63);
    b1.insertitem(70);
    b1.insertitem(130);
    b1.insertitem(150);
    b1.insertitem(53);
    b1.insertitem(58);
    b1.insertitem(68);
    b1.insertitem(75);
    b1.insertitem(135);
    b1.insertitem(145);
    b1.insertitem(160);
    b1.insertitem(57);
    b1.insertitem(73);
    b1.insertitem(78);
    b1.insertitem(142);
    b1.insertitem(155);
    b1.InorderTraversal();
    b1.Delete(58);
    b1.InorderTraversal();
}
*/
/*
node* pre(node *temp)
{
    if(temp->lchild==NULL)
    {
        cout<<temp->item<<" ";
        if(temp->rchild!=NULL)
            pre(temp->rchild);
    }
    else
    {
        temp=temp->lchild;
        pre(temp);
    }
}
*/
/*
node* pre(node *temp)
{
    if(temp->lchild==NULL)
    {

    }
    if(temp->lchild!=NULL)
        temp=temp->lchild;
    pre(temp);
}
*/
/*
void BST::InorderTraversal()
{
    lchild
    node
    rchild


    pre(temp)
    node *temp=root;

    if(temp->lchild!=NULL)
        temp=temp->lchild;

}
*/
