#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class t>
class Stack
{
    struct Node
    {
        t data;
        Node *link;
    };
    Node *tail;
    int sz;
    public:
    Stack()
    {
        tail = NULL;
        sz = 0;
    }
    void Push(t x)
    {
        Node *a = new Node;
        a->data = x;
        if(tail == NULL)
        {
            a->link = NULL;
            tail = a;
            sz++;
            return;
        }
        a->link = tail;
        tail = a;
        sz++;
    }
    void Pop()
    {
        if(tail == NULL)
        {
            return;
        }
        Node *a = tail;
        tail = tail->link;
        delete a;
        sz--;
    }
    int Size()
    {
        return sz;
    }
    t Top()
    {
        if(sz == 0)
        {
            return 0;
        }
        return tail->data;
    }
};
int main()
{
    Stack<int>st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    st.Push(6);
    cout << st.Size() << endl;
    st.Pop();
    st.Pop();
    cout << st.Top() << endl;
}
