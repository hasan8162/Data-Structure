#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<typename t>
class List{

  struct Node{
    t data;
    Node *link;
  };
  Node *head;

  public:
  List()
  {
    head = NULL;
  }
  void InsertAtTheEnd(t x)
  {
    Node *a = new Node;
    a->data = x;
    a->link = NULL;
    if(head == NULL)
    {
      head = a;
      return;
    }
    Node *temp = head;
    while(temp->link != NULL)
    {
      temp = temp->link;
    }
    temp->link = a;
  }

  void InsertByPosition(int pos, t x)
  {
    Node *a = new Node;
    a->data = x;
    if(head == NULL && pos > 1) return;

    if(pos == 1)
    {
      a->link = head;
      head = a;
      return;
    }
    Node *temp=head;
    for(int i=2; i<pos; i++)
    {
      if(temp->link == NULL) return;
      temp = temp->link;
    }
    a->link = temp->link;
    temp->link=a;
  }
  void DeleteByPosition(int pos)
  {
    if(head == NULL) return;

    if(pos == 1)
    {
      head = head->link;
    }
    Node *temp = head;
    for(int i=2; i<pos; i++)
    {
      temp = temp->link;
      if(temp->link == NULL) return;

    }
    temp->link = temp->link->link;
  }

  void print()
  {
    Node *temp = head;
    if(head == NULL) return;
    while(temp != NULL)
    {
      cout << temp->data << endl;
      temp = temp->link;
    }
  }
};
int main()
{
  List<int>lst;
  lst.InsertAtTheEnd(1);
  lst.InsertAtTheEnd(2);
  lst.InsertAtTheEnd(3);
  lst.InsertAtTheEnd(4);
  lst.InsertAtTheEnd(5);
  lst.InsertAtTheEnd(6);
  lst.InsertAtTheEnd(7);
  lst.InsertAtTheEnd(8);
  lst.InsertByPosition(3, 9);
  lst.DeleteByPosition(1);
  lst.print();
}
