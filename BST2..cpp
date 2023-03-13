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
public:
    BST();
    void insertitem(int data);
   // void preorderTraversal();
    void InorderTraversal();
  //  void postorderTraversal();
  //  ~BST();
    void pre(node *temp);
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
        Deletion_one_child(parptr,ptr);
    else if(ptr->lchild==NULL && ptr->rchild==NULL)
        Deletion_no_child(parptr,ptr);
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
        Deletion_two_child(parptr,ptr);



    void Deletion_no_child(node *parptr,node*ptr)
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

    void Deletion_one_child(node *parptr,node *ptr) //But how this function can access parptr ????
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

    void Deletion_two_child(node *ptr) //here traversing is required to find the successor and predecor
    {//predecsor
        node *temp,partemp;
        if(ptr==root)
        {

        }
        else
        {
            node*parpoint=NULL;
            node *point=ptr;
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
                parpoint->rchild=NULL;
                delete point;
            }
            else //point->lchild!=NULL;
            {
                parpoint->rchild=point->lchild;
                delete point;
            }
        }
    }

    /*
    Deletion_one_child();
    Deletion_Two_child();
    Deletion_zero_child();
    */
}
int main()
{
    BST b1;
    b1.insertitem(56);
    b1.insertitem(52);
    b1.insertitem(23);
    b1.insertitem(60);
    b1.insertitem(28);
    b1.insertitem(73);
    b1.insertitem(85);
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
public:
    BST();
    void insertitem(int data);
   // void preorderTraversal();
    void InorderTraversal();
  //  void postorderTraversal();
  //  ~BST();
    void pre(node *temp);
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
        Deletion_one_child(parptr,ptr);
    else if(ptr->lchild==NULL && ptr->rchild==NULL)
        Deletion_no_child(parptr,ptr);
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
        Deletion_two_child(parptr,ptr);



    void Deletion_no_child(node *parptr,node*ptr)
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

    void Deletion_one_child(node *parptr,node *ptr) //But how this function can access parptr ????
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

    void Deletion_two_child(node *ptr) //here traversing is required to find the successor and predecor
    {//predecsor
        node *temp,partemp;
        if(ptr==root)
        {

        }
        else
        {
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
                parpoint->rchild=NULL;
                delete point;
            }
            else //point->lchild!=NULL;
            {
                parpoint->rchild=point->lchild;
                delete point;
            }
        }
    }

    Deletion_one_child();
    Deletion_Two_child();
    Deletion_zero_child();
}
int main()
{
    BST b1;
    b1.insertitem(56);
    b1.insertitem(52);
    b1.insertitem(23);
    b1.insertitem(60);
    b1.insertitem(28);
    b1.insertitem(73);
    b1.insertitem(85);
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

