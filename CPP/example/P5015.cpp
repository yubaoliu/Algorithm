// P5015 [NOIP2018 普及组] 标题统计
// https://www.luogu.com.cn/problem/P5015
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt = 0;
    string s;
    getline(cin, s);
    for (size_t i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            cnt++;
    cout << cnt;
    return 0;
}