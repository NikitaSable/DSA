#include<iostream>

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

node* insertBST(node *root, int val)
{
    if(root==NULL)
    {
        return new node(val);
    }

    if(root->data>val)
    {
        root->left=insertBST(root->left, val);
    }
    else 
    {
        root->right=insertBST(root->right,val);
    }
    return root;
}
node* inorderSucc(node* root)
{
    node* curr = root;

    while(curr && curr->left!=NULL)
    {
        curr = curr->left;
    }

    return curr;
}
node* deleteNode(node* root, int key)
{

    if(key<root->data)
    {
        root->left=deleteNode(root->left, key);
    }
    else if(key>root->data)
    {
        root->right=deleteNode(root->right,key);
    }
    else 
    {
        if(root->left==NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }

        node* temp = inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right, key);

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

node* searchInBST(node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        return root;
    }

    if(root->data>key)
    {
       
        return searchInBST(root->left, key);
    }
    else{
        return searchInBST(root->right, key);
    }
    return root;
}

int main()
{
    node* root=NULL;
    root = insertBST(root,1);
    insertBST(root,2);
    insertBST(root,4);
    insertBST(root,3);
    insertBST(root,6);
    insertBST(root,7);
    insertBST(root,5);

    inorder(root);
    if(searchInBST(root, 9) == NULL)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"found";
    }
    deleteNode(root, 5);
    inorder(root);
    return 0;
}
