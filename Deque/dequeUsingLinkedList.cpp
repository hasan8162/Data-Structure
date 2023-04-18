#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class t>
class DeQueue
{
    int sz = 0;
    struct Node{
        t data;
        Node *link1, *link2;
    };
    Node *head, *tail;
    public:
    DeQueue()
    {
        head = NULL;
        tail = NULL;
    }
    void Push_back(t x){
        Node *a = new Node;
        a->data = x;
        if(head == NULL)
        {
            head = a;
            tail = a;
            a->link1 = NULL;
            a->link2 = NULL;
            sz++;
            return;
        }
        tail->link1 = a;
        a->link1 = NULL;
        a->link2 = tail;
        tail = a;
        sz++;
    }
    void Push_front(t x){
        Node *a = new Node;
        a->data = x;
        if(head == NULL)
        {
            head = a;
            tail = a;
            a->link1 = NULL;
            a->link2 = NULL;
            sz++;
            return;
        }
        head->link2 = a;
        a->link1 = head;
        a->link2 = NULL;
        head = a;
        sz++;
    }
    void Pop_back(){

        if(head == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
         Node *a = tail;
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else{
            tail = tail->link2;
        }
        sz--;
        delete a;

    }
    void Pop_front(){

         if(head == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
         Node *a = head;
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else{
            head = head->link1;
        }
        sz--;
        delete a;

    }
    t Front()
    {
        if(head == NULL)
        {
            return 0;
        }
        return head->data;
    }
    t Back()
    {
         if(head == NULL)
        {
            return 0;
        }
        return tail->data;
    }
    int Size()
    {
        return sz;
    }
};
int main()
{
    DeQueue<int>q;
    q.Push_back(1);
    q.Push_back(2);
    q.Push_back(3);
    q.Push_back(4);
    q.Push_back(5);
    q.Push_back(6);
    q.Push_front(1);
    q.Push_front(2);
    q.Pop_back();
    q.Pop_back();
    q.Pop_back();
    q.Pop_front();
    q.Pop_front();
    cout << q.Size() << endl;
    cout << q.Front() << endl;
    cout << q.Back() << endl;
}
