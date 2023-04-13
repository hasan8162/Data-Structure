#include<bits/stdc++.h>
using namespace std;

template<typename t>
class Stack
{
    t a[1001];
    int Top, sz;
    public:

    Stack()
    {
        Top = 0;
    }
    void Push(t x)
    {
        if(Top + 1 > 1000)
        {
            return;
        }
        Top++;
        a[Top] = x;
    }
    void Pop()
    {
        if(Top == 0) return;

        Top--;
    }
    t TOP()
    {
        return a[Top];
    }
    int Size()
    {
        return Top;
    }
};
int main()
{
    Stack<int>st;
    st.Push(3);
    st.Push(4);
    st.Push(6);
    st.Push(7);
    st.Push(8);
    st.Pop();
    cout << st.TOP() << endl;
    cout << st.Size() << endl;
}
