#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s;
    public:
        void push(int val);
	    int pop();
};

void Queue::push(int val)
{
    s.push(val);
}

int Queue::pop()
{
    if(s.empty())
        return -1;
    
    int x = s.top();
    s.pop();
    if(s.empty())
        return x;
    
    int item= pop();
    s.push(x);
    return item;
}

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
 
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    return 0;
}