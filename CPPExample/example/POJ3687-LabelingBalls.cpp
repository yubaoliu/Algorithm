// https://www.youtube.com/watch?v=gpBHlWRAzh0&list=PLkNxDxyJqb-xD5EbDuIYC35Adq5f_w9CR&index=23
/*
1. Mehod1: 出度为0的先分配, 与拓扑排序正好相反
2. Method2: 建反向图
*/
// 建反向图
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 205;
int map[maxn][maxn], in[maxn], w[maxn];
int n, m;
bool flag;
void TopoSort()
{
    flag = 0;
    for (int i = n; i > 0; i--) // i 用于分配重量,因为先从大的重量开始分,所以倒序循环
    {
        int t = -1;
        // 从大号开始找入度是0的节点, 如果压栈的话,不能保证编号大的节点先出栈
        // or 使用优先队列,把编号做为优先级
        for (int j = n; j > 0; j--)
            if (!in[j])
            {
                t = j;
                break;
            }
        if (t == -1) // 有环
        {
            flag = 1;
            return;
        }
        in[t] = -1;
        w[t] = i; // 分配重量
        // 更新所有邻接点
        for (int j = 1; j <= n; j++)
            if (map[t][j])
                in[j]--;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(map, 0, sizeof(map));
        memset(in, 0, sizeof(in));
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            if (!map[v][u]) // 检查重复边
            {
                map[v][u] = 1;
                in[u]++;
            }
        }
        TopoSort();
        if (flag) // 有环,没有拓扑序
        {
            cout << -1 << endl;
            continue;
        }
        // 输出重量序列
        for (int i = 1; i < n; i++)
            cout << w[i] << " ";
        cout << w[n] << endl;
    }
    return 0;
}