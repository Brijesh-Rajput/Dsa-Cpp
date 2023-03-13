#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class BSTnew
{
private:
    struct node
    {
        node *lchild;
        int item;
        node *rchild;
    };
    node *root;
protected:
    void Nochild(node *parptr,node *ptr);
    void Twochild_predecor(node *ptr);
    void Twochild_successor(node *ptr);
    void Onechild(node *parptr,node *ptr);
public:
    BSTnew();
    void insertItem(int data);
    void preorder(node *ptr);
    void inorder(node *ptr);
    void postorder(node *ptr);
    node* DeleteNew(node *root,int data);
    void Delete(int data);
    node* getroot(){return root;}
    int rootvalue(){return root->item;}
    ~BSTnew();
};
BSTnew::BSTnew()
{
    root=NULL;
}
void BSTnew::insertItem(int data)
{
    node *ptr=new node;
    ptr->lchild=NULL;
    ptr->item=data;
    ptr->rchild=NULL;

    if(root==NULL)
        root=ptr;
    else
    {
        node *temp=root;

        while(1)
        if(temp->item==data)
        {
            cout<<"Duplicate value so, Insertion is not possilble"<<endl;
            break;
        }
        else if(temp->item>data)
        {
            if(temp->lchild==NULL)
            {
                temp->lchild=ptr;
                break;
            }
            temp=temp->lchild;
        }
        else
        {
            if(temp->rchild==NULL)
            {
                temp->rchild=ptr;
                break;
            }
            temp=temp->rchild;
        }
    }
}
void BSTnew::preorder(node *ptr)
{
   //  node leftchild rightchild
   if(ptr)
   {
        cout<<ptr->item<<" ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
   }
}
void BSTnew::inorder(node *ptr)
{
    if(ptr)
    {
        inorder(ptr->lchild);
        cout<<ptr->item<<" ";
        inorder(ptr->rchild);
    }
}
void BSTnew::postorder(node *ptr)
{
    if(ptr)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout<<ptr->item<<" ";
    }
}
void BSTnew::Delete(int data)
{
    //tree empty
    //element not found
    //element found
        //-no child
        //-one child
        //-two child
    if(root==NULL)
        cout<<"underflow(Tree is Empty)"<<endl;
    else
    {
        node *t1=root,*t2=NULL;
        while(t1)
        {
            if(t1->item==data)
            {//Data found
                //no child
                //one child
                //two child

                if(t1->lchild==NULL && t1->rchild==NULL)
                    Nochild(t2,t1);
                else if(t1->lchild!=NULL && t1->rchild!=NULL)
                    Twochild_successor(t1); //Or Twochild_predecor(t1);
                else
                    Onechild(t2,t1);
                break;
            }
            else if(t1->item>data)
            {
                t2=t1;
                t1=t1->lchild;
                /*
                if(t1==NULL || t2->item>data && t1->item<data)
                {
                    cout<<"Element Not found"<<endl;
                    break;
                }
                */
            }
            else
            {
                t2=t1;
                t1=t1->rchild;
                /*
                if(t1==NULL || t2->item>data && t1->item<data)
                {
                    cout<<"Element Not found"<<endl;
                    break;
                }
                */
            }
        }
        if(t1==NULL)
           cout<<"Element Not found"<<endl;
    }
}
void BSTnew::Nochild(node *parptr,node *ptr)
{
    if(parptr==NULL)
        root=NULL;
    else if(parptr->lchild==ptr)
        parptr->lchild=NULL;
    else
        parptr->rchild=NULL;
    delete ptr;
}
void BSTnew::Onechild(node *parptr,node *ptr)
{
    if(parptr==NULL)
    {
        if(ptr->lchild==NULL)
            root=ptr->rchild;
        else
            root=ptr->lchild;
    }
    else
    {
        if(ptr->lchild==NULL)
            if(parptr->rchild==ptr)
                parptr->rchild=ptr->rchild;
            else
                parptr->lchild=ptr->rchild;
        else
             if(parptr->lchild==ptr)
                parptr->lchild=ptr->lchild;
             else
                parptr->rchild=ptr->lchild;
    }
    delete ptr;
}
void BSTnew::Twochild_predecor(node *ptr)
{
    //predecor -> traversing , ptr->lchild->rchild!=NULL
    //successor -> traversing , ptr->rchild->lchild!=NULL

    //predeccor
    node *t1=ptr->lchild,*t2=ptr;
    while(t1->rchild)
    {
        t2=t1;
        t1=t1->rchild;
    } //t1->rchild==NULL compulsory in predecor after while loop
    ptr->item=t1->item;
    if(t2==ptr)
        t2->lchild=t1->lchild;
    else
        t2->rchild=t1->lchild;
    delete t1;
}
void BSTnew::Twochild_successor(node *ptr)
{
    //predecor -> traversing , ptr->lchild->rchild!=NULL
    //successor -> traversing , ptr->rchild->lchild!=NULL

    //successor
    node *t1=ptr->rchild,*t2=ptr;
    while(t1->lchild)
    {
        t2=t1;
        t1=t1->lchild;
    } //t1->lchild==NULL compulsory in successor after while loop -->IMP
    ptr->item=t1->item;
    if(t2==ptr)
        t2->rchild=t1->rchild;
    else
        t2->lchild=t1->rchild;
    delete t1;
}
BSTnew::~BSTnew()
{
    while(root)
        Delete(rootvalue());
    if(root==NULL)
        cout<<"Destructor work successful";
}
int main()
{
    BSTnew t1;
    int tree[25]={98,60,120,50,65,110,140,40,55,63,70,130,150,53,58,68,75,135,145,160,57,73,78,142,155};
    for(int i=0;i<25;i++)
        t1.insertItem(tree[i]);

    //traversing
    cout<<"preorder:- ";
    t1.preorder(t1.getroot());
    cout<<endl;
    cout<<"Inorder:- ";
    t1.inorder(t1.getroot());
    cout<<endl;
    cout<<"postorder:- ";
    t1.postorder(t1.getroot());
    cout<<endl;

    t1.insertItem(110);
    t1.Delete(65);
    t1.Delete(120);
    t1.Delete(145);
    t1.Delete(160);

    //traversing
    cout<<"preorder:- ";
    t1.preorder(t1.getroot());
    cout<<endl;
    cout<<"Inorder:- ";
    t1.inorder(t1.getroot());
    cout<<endl;
    cout<<"postorder:- ";
    t1.postorder(t1.getroot());
    cout<<endl;

    getch();
}
/*
void BSTnew::Nochild(node *parptr,node *ptr)
{
    //ptr==root node //that means parptr contains NULL
    if(parptr==NULL)
        root=NULL;
    else if(parptr->lchild==ptr)
        parptr->lchild=NULL;
    else
        parptr->rchild=NULL;
    delete ptr;
}
void BSTnew::Onechild(node *parptr,node *ptr)
{
    //if parptr==NULL
    //only lchild Or only rchild
    if(parptr==NULL)
    {
        if(ptr->lchild)
            root=ptr->lchild;
        else
            root=ptr->rchild;
    }
    else
    {
        if(parptr->lchild==ptr && ptr->rchild==NULL)
            parptr->lchild=ptr->lchild;
        else if(parptr->lchild==ptr && ptr->lchild==NULL)  //lchild==NULL
            parptr->lchild=ptr->rchild;
        else if(parptr->rchild==ptr && ptr->rchild==NULL)
            parptr->rchild=ptr->lchild;
        else if(parptr->rchild==ptr && ptr->lchild==NULL)  //lchild==NULL
            parptr->rchild=ptr->rchild;
    }
    delete ptr;
}

void BSTnew::Twochild(node *parptr,node *ptr)
{
    //if parptr==NULL
    //predecor and successor

    //successor is used
    if(parptr==NULL)
    {
        node *t1=ptr->rchild,node*t2=ptr;
        //traversing to search in right sub-tree,value just greater than ptr->item (root node b/c parptr==NULL)
        while(1)
        {
            if(t1->lchild1!=NULL)
            {
                t2=t1;
                t1=t1->lchild;
            }
            ptr->item=t1->item;
            t2->lchild=t1->rchild; //we know that t1->lchild==NULL , its confirm
            delete t1;
            break;
        }
    }
    else
    {

    }
}
BSTnew::~BSTnew()
{
    while(root)
        Delete(getroot()->item);
   if(root==NULL)
    cout<<"Hello";
    //wrong --->  Delete(*getroot());//Tree is Empty
}
*/
