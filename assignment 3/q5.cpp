// 5. Write a program for the evaluation of Postfix expression.



#include <iostream>
#include <stack>
using namespace std;

int solve(int v1, int v2, char ch)
{
    if (ch == '+')
        return v1 + v2;
    else if (ch == '-')
        return v1 - v2;
    else if (ch == '*')
        return v1 * v2;
    else if (ch == '/')
        return v1 / v2;
    return 0; // default
}

int main()
{
    string s = "264*8/+3-"; // example postfix expression

    stack<int> val;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            val.push(s[i] - '0'); // convert char to int
        }
        else
        {
            int v2 = val.top();
            val.pop();
            int v1 = val.top();
            val.pop();
            int ans = solve(v1, v2, s[i]);
            val.push(ans);
        }
    }

    cout << "Result: " << val.top();
}
