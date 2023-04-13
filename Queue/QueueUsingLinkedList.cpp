#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class t>
class Queue
{
    struct Node
    {
        t data;
        Node *link;
    };
    Node *head, *tail;
    int sz;
    public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    void Push(t x)
    {
        Node *a = new Node;
        a->data = x;
        a->link = NULL;
        if(head == NULL)
        {
            head = a;
            tail = a;
            sz++;
            return;
        }
        tail->link = a;
        tail = a;
        sz++;
    }
    void Pop()
    {
        if(head == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        if(sz == 1)
        {
            tail = NULL;
        }
        Node *a = head;
        head = head->link;
        delete a;
        sz--;
    }
    int Size()
    {
        return sz;
    }
    t Front()
    {
        if(sz == 0)
        {
            return 0;
        }
        return head->data;
    }
};
int main()
{
    Queue<int>q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);
    q.Push(6);
    cout << q.Size() << endl;
    q.Pop();
    q.Pop();
    cout << q.Front() << endl;
}
