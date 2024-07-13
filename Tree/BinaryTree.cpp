#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertBST(Node *root, int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(val < root->data)
    {
        root->left=insertBST(root->left, val);
    }
    else
    {
        root->right=insertBST(root->right, val);
    }

    return root;

}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";

}
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);

}

int main()
{
    Node* root=NULL;

    root = insertBST(root,1);
    insertBST(root,2);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 5);
    insertBST(root, 6);
    insertBST(root, 7);

    cout<<"inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"preorder"<<endl;
    preorder(root);
    cout<<endl;
    return 0;
}
