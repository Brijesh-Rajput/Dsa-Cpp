#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
//BST::node* pre(BST::node *temp);
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
    node
    void insertitem(int data);
   // void preorderTraversal();
    void InorderTraversal();
  //  void postorderTraversal();
  //  ~BST();
};
BST::BST()
{
    root=NULL;
}
void BST::insertitem(int data)
{
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
BST::node* pre(node *temp)
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

