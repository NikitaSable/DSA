#include<iostream>

using namespace std;

class node
{
    public:
        node* next;
        int data;

    node(int val)
    {
        next = NULL;
        data= val;
    }
};

void InserAtHead(node* &head, int val)
{
    node* n = new node(val);

    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);

    if(head==NULL)
    {
        head = n;
        return;
    }

    node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = n;
}

bool search(node* head, int key)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }

        temp=temp->next;
    }
    return false;
}

void deletehead(node* &head)
{
    node* temp = head;
    head=head->next;

    delete temp;
}

void deleteNode(node* &head, int val)
{
    node* temp = head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }

    node* todelete = temp->next;
    temp->next= temp->next->next;

    delete todelete;
}

node* reverseList(node* &head)
{
    node* preptr = NULL;
    node* currptr = head;
    node* nextpre;

    while(currptr!= NULL)
    {
        nextpre=currptr->next;
        currptr->next=preptr;

        preptr=currptr;
        currptr=nextpre;
    }

    return preptr;
}


node* reveseAtk(node* &head, int k)
{
    node* preptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;
    while(currptr!=NULL && count<k)
    {
        nextptr=currptr->next;
        currptr->next=preptr;
        preptr=currptr;
        currptr=nextptr;

        count++;
    }

    if(nextptr!=NULL)
    {
        head->next = reveseAtk(nextptr,k);
    }

    return preptr;
}

void display(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,4);    
    insertAtTail(head,5);
    insertAtTail(head,3);
    InserAtHead(head,0);
    display(head);
    // cout<<search(head, 4);
    // deleteNode(head, 4);
    // deletehead(head);
    // reverseList(head);
    node* newhead=reveseAtk(head,2);
    display(newhead);

    return 0;
}
