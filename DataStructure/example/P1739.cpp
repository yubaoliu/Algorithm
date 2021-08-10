// https://www.luogu.com.cn/problem/P1739
/*
假设一个表达式有英文字母（小写）、运算符（+，—，*，/）和左右小（圆）括号构成，以“@”作为表达式的结束符。请编写一个程序检查表达式中的左右圆括号是否匹配，若匹配，则返回“YES”；否则返回“NO”。表达式长度小于255，左圆括号少于20个。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    stack<char> s;
    while (cin >> c && c != '@')
    {
        if (c == '(')
        {
            s.push(c);
        }
        if (c == ')')
        {
            if (!s.empty())
            {
                s.pop();
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (s.empty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}