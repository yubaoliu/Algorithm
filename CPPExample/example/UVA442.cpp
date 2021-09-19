// UVA442 矩阵链乘 Matrix Chain Multiplication
// https://www.luogu.com.cn/problem/UVA442
#include <bits/stdc++.h>
using namespace std;
const int maxsize = 26 + 5;

struct Matrix
{
    int a, b; // row and column
    Matrix(int a = 0, int b = 0) : a(a), b(b) {}
} m[maxsize];

stack<Matrix> s;
int main()
{
    int n;
    char c;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        int k = c - 'A';
        cin >> m[k].a >> m[k].b;
    }
    while (cin >> str)
    {
        int len = str.length();
        bool error = false;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (isalpha(str[i]))
                s.push(m[str[i] - 'A']);
            else if (str[i] == ')')
            {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if (m1.b != m2.a)
                {
                    error = true;
                    break;
                }
                ans += m1.a * m1.b * m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if(error)
            cout<<"error"<<endl;
        else
            cout<<ans<<endl;
    }
}