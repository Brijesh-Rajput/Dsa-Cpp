#include<iostream>
#include<stdio.h>
#include"BSTnew.cpp"
using namespace std;
BSTnew::node* BSTnew::DeleteNew(node *root,int data)
{
    node *temp;
    if(root==NULL)
        printf("No such Elemnt Exists");
    else if(data<root->data)
        root->left=DeleteNew(root->left,data)
    else if(data>root->data)
        root->right=DeleteNew(root->right,data)
}
