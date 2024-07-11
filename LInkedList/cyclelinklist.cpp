#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void InsertAtHead(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;

    n->next=head;
    head=n;
    
}

void InsertAtTail(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;

    if(head==NULL)
    {
        head=n;
        return;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

}

void makeCycle(node* &head, int pos)
{
    node* temp=head;
    node* startnode;

    int count=1;

    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startnode=temp;
        }

        temp=temp->next;
        count++;
    }

    temp->next=startnode;
}

bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
            return true;
        }
    }
}

void deleteCycle(node* &head)
{
    node* slow=head;
    node* fast=head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=NULL;
    
}

void display(node* head)
{
    node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
}

int main()
{
    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtHead(head,0);
    makeCycle(head,2);
    cout<<detectCycle(head)<<endl;
    // display(head);
    deleteCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head); 
    return 0;
}