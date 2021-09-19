/*
https://vjudge.net/problem/POJ-3258
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 50050
int L, n, m;
int dis[maxn];

bool judge(int x)
{
    int num = n - m; // 减掉m个石头
    int last = 0;
    for (int i = 0; i < num; i++) // 对于这些石头,要使任意间距不小于x
    {
        int cur = last + 1;
        while (cur <= n && dis[cur] - dis[last] < x) // 中间的石头应该被去除
            cur++;                                   // 累计位置
        if (cur > n)
            return 0;
        last = cur;
    }
    return 1;
}

int main()
{
    cin >> L >> n >> m; // L: 河流的长度, n: 石头数, m: 移除的石头数
    if (n == m)
    {
        cout << L << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) // 输入n个距离
        cin >> dis[i];
    dis[0] = 0;             //增加开始点
    dis[n + 1] = L;         // 增加结束点
    sort(dis, dis + n + 2); //nlogn
    int left = 0, right = L;
    while (right - left > 1)
    {
        int mid = (right + left) / 2;
        if (judge(mid))
            left = mid; // left 记录合法的mid值
        else
            right = mid;
    }
    cout << left << endl;
    return 0;
}