// P2550 [AHOI2001]彩票摇奖
// https://www.luogu.com.cn/problem/P2550
#include <bits/stdc++.h>
using namespace std;
int f[35], p[10]; //f 统计中奖号码是否出现过, p 相同数字的彩票有几张
int main()
{
    int n, m, cnt = 0;
    cin >> n;                    //n 张彩票
    for (int i = 1; i <= 7; i++) // 中奖号码
    {
        cin >> m;
        f[m] = 1;
    }
    // 输入n张彩票
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        for (int i = 1; i <= 7; i++)
        {
            cin >> m;
            if (f[m])  // 中奖号码
                cnt++; // 相同数字的个数
        }
        p[cnt]++; // 相同数字是cnt的彩票个数
    }
    for (int i = 7; i > 1; i--)
    {
        cout << p[i] << " ";
    }
    cout << p[1];

    return 0;
}