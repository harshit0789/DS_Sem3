#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
void push1(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void pop1()
{
    if (q.empty())
    {
        cout << "Stack Empty" << endl;
        return;
    }
    q.pop();
}

int top1()
{
    if (q.empty())
        return -1;
    else
        return q.front();
}

bool empty1()
{
    if (q.empty())
        return true;
    else
        return false;
}

int main()
{
    push1(5);
    push1(15);
    push1(25);
    cout << "Top: " << top1() << endl;
    pop1();
    cout << "Top after pop:" << top1() << endl;
}
