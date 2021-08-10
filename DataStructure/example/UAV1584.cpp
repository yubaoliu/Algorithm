// UVA1584 环状序列 Circular Sequence
// https://www.luogu.com.cn/problem/UVA1584
#include <bits/stdc++.h>
using namespace std;
int n, len;
string s;
bool les(int p, int q)
{
    for (int j = 0; j < len; j++)
        if (s[p + j] != s[q + j])
            return s[p + j] < s[q + j];
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> s;
        len = s.length();
        string mins = s;
        int ans = 0; //最小串的开始位置
        s += s;
        // for (int j = 1; j < len; j++)
        // {
        //     string sc = s.substr(j, len);
        //     if (sc < mins)
        //         mins = sc;
        // }
        for (int j = 1; j < len; j++)
        {
            if (les(j, ans))
                ans = j;
        }
        mins = s.substr(ans, len);
        cout << mins << endl;
    }

    return 0;
}