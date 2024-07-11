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

    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val)
{
    node* n= new node(val);
    node* temp = head;

    if(head==NULL)
    {
        InsertAtHead(head,val);
        return;
    }

    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->next=head;

}

void deleteAtHead(node* &head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    node* todelete = head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}

void deleteNode(node* head, int val)
{
    if(val==1)
    {
        deleteAtHead(head);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    int count = 0;

    while(count!=val-1)
    {
        temp=temp->next;
        count++;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;

}

void displya(node* head)
{
    node* temp = head;
    
    do
    {
        /* code */
        cout<<temp->data<<"->";
        temp=temp->next;
    } while (temp!=head);
    cout<<"NULL"<<endl;
    
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    InsertAtHead(head,0);
    displya(head);
    deleteNode(head, 2);
    deleteAtHead(head);
    displya(head);
    return 0;
}