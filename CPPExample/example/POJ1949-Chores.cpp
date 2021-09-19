/*
关键路径
方法:
1) SPFA
2) 拓扑序排序
*/
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 10010
int d[maxn], n;
int readin()
{
    int x = 0, s = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            s = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * s;
}
int main()
{
    int ans = 0, w, num, y;
    n = readin();
    for (int i = 1; i <= n; i++)
    {
        w = readin();
        d[i] = w;
        num = readin();
        for (int j = 1; j <= num; j++)
        {
            y = readin();
            d[i] = max(d[i], d[y] + w);
        }
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}