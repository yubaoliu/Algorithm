// https://www.luogu.com.cn/problem/P1138
// P1138 第k小整数
/*
现有nn个正整数，n≤10000n，要求出这n个正整数中的第k个最小整数（相同大小的整数只计算一次），k≤1000，正整数均小于30000。
*/
// 先排序,再去重
#include <bits/stdc++.h>
using namespace std;
int n, k, a[10005];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n); // descent: greater<int>()
    int n2 = unique(a, a + n) - a; // 返回去重之后的元素个数
    if (k <= n2)
        cout << a[k - 1];
    else
        cout << "NO RESULT";
    return 0;
}