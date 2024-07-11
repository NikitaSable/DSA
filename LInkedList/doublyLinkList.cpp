#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void InsertAtHead(node* &head, int val)
{
    node* n= new node(val);
    n->next=head;
    if(head!=NULL)
    {
    head->prev=n;
    }
    head=n;
}

void InsertAtTail(node* &head, int val)
{
    node* n=new node(val);
    node* temp = head;

    if(head==NULL)
    {
        InsertAtHead(head,val);
        return;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;

}
void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}

void deleteNode(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;
    int cont = 0;

    if (val==1)
    {
        deleteAtHead(head);
        return;
    }

    while(temp!=NULL && cont!=val)
    {
        temp=temp->next;
        cont++;
    }

    temp->prev->next=temp->next;

    if(temp->next!=NULL){
    temp->next->prev=temp->prev;
    }


    node* todelete = temp;

    delete todelete;
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
    node* head=NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtHead(head,0);
    display(head);
    // deleteAtHead(head);
    deleteNode(head,1);
    display(head);
    return 0;
}