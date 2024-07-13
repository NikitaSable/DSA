#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insertNode(node* root, int val)
{
    if(root==NULL)
    {
        return new node(val);
    }

    if(root->data>val)
    {
       root->left =  insertNode(root->left, val);
    }
    else
    {
        root -> right = insertNode(root->right,val);
    }

    return root;
}

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelOrder(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
    }

}
int main()
{
    node* root = NULL;
    root = insertNode(root, 1);
    insertNode(root,2);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,9);
    insertNode(root,6);
    insertNode(root,3);
    inorder(root);
    return 0;
}