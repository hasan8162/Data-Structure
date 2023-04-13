#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class t>
class Queue
{
    t a[1001], maxi = 1000;
    int sz, f, r;
    public:
    Queue()
    {
        sz = 0;
        f = 0;
        r = 0;
    }
    void Push(t x)
    {
        if(f == 0 && r == 0)
        {
            f++;
            r++;
            a[f] = x;
            sz++;
            return;
        }
        if(f == 1 && r == maxi || r + 1 == f)
        {
            cout << "Overflow" << endl;
            return;
        }
        if(r + 1 > maxi)
        {
            r = 1;
            a[r] = x;
            sz++;
            return;
        }
        r++;
        a[r] = x;
        sz++;
    }
    void Pop()
    {
        if(f == 0)
        {
            cout << "Underflow" << endl;
            return;
        }
        if(r == f)
        {
            r = 1;
            f = 1;
            sz--;
            return;
        }
        if(f == maxi)
        {
            f = 1;
            sz--;
            return;
        }
        f++;
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
        return a[f];
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
    q.Pop();
    q.Pop();
    cout << q.Size() << endl;
    cout << q.Front() << endl;
}
