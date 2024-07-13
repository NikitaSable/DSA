#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right=NULL;
    }
};

node* creationBST(node* root)
{
    int data;
    cout<<"Enter the root data: "<<endl;
    cin>>data;
    root = new node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter the data for left node of: "<<data<<endl;
    root->left=creationBST(root->left);
    cout<<"Enter the data for left node of: "<<data<<endl;
    root->right=creationBST(root->right);

    return root;
}

void levelOrderTravelser(node* root)
{
    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else 
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = creationBST(root);
    // creationBST(root,7);
    // creationBST(root,1);
    // creationBST(root,11);
    // creationBST(root,5);
    // creationBST(root,17);
    // creationBST(root,2);
    levelOrderTravelser(root);
    return 0;
}


 /**cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root= new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left"<<data<<endl;
    root->left = creationBST(root->left);
    cout<<"Enter data for inserting in right"<<data<<endl;
    root->right = creationBST(root->right);
    
    return root;

    **/