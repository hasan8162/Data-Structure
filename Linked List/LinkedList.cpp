#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
    int data;
    Node *link;
};
Node* head;
void insertEnd(int x)
{
    Node *a=new Node;
    a->data=x;
    a->link=NULL;

    if(head==NULL)
    {
        head = a;
        return;
    }

    Node *temp = head;

    while(temp->link != NULL)
    {
        temp=temp->link;
    }

    temp->link=a;

}

void insertByPosition(int pos, int x)
{
    Node *a=new Node;
    a->data=x;

    if(head==NULL && pos > 1) return;

    else if(head==NULL)
    {
        a->link=NULL;
        head=a;
        return;
    }

    else if(pos==1)
    {
        a->link=head;
        head=a;
    }

    else{
         Node *temp=head;
         for(int i=2; i<pos; i++)
         {
            if(temp->link == NULL) return;

            temp=temp->link;
         }
         a->link=temp->link;
         temp->link=a;
    }

}

void print()
{
    if(head==NULL) return;

    Node *a=head;

    while(a!=NULL)
    {
        cout << a->data << endl;
        a=a->link;
    }
}

void DeleteByPosition(int pos)
{
    Node *temp=head;
    if(head == NULL) return;

    if(pos==1)
    {
        head=head->link;
        return;
    }
    for(int i=2; i<pos; i++)
    {
        if(temp->link != NULL)
        temp=temp->link;
        else return;
    }
    Node *a=temp->link;
    temp->link=temp->link->link;
    delete a;
}
int main()
{
   head = NULL;
   insertEnd(1);
   insertEnd(2);
   insertEnd(3);
   insertEnd(4);
   insertEnd(5);
   insertEnd(6);
   insertEnd(7);
   insertEnd(8);
   insertEnd(9);
   insertEnd(10);
   DeleteByPosition(2);
   insertByPosition(5, 12);
   print();
}
