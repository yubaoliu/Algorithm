/*
1) 用Floyd判断连通性
2) 用SPFA判断有没有正环,即cnt[v]>=n则有正环,有正环环上一点到终点是否连通. 没有环的话,则判断到达终点最长的通路能量值是否大于0
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int n;
int energy[maxn];
int power[maxn];
int cnt[maxn];
bool g[maxn][maxn], vis[maxn]; // vis标记入队
bool reach[maxn][maxn];        // 是否连通
// 判断任意两点之间的连通性
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (reach[i][j] || (reach[i][k] && reach[k][j]))
                    reach[i][j] = true;
}
bool spfa(int s)
{
    queue<int> q;
    memset(power, 0, sizeof(power));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    power[s] = 100;
    q.push(s);
    vis[s] = 1;
    cnt[s]++; // 统计入队次数
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        vis[v] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (g[v][i] && power[i] < power[v] + energy[i] && power[v] + energy[i] > 0)
            {
                power[i] = power[v] + energy[i];
                if (!vis[i])
                {
                    if (++cnt[i] >= n)
                        return reach[v][n]; // 有正环
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    return power[n] > 0;
}
void solve()
{
    while (cin >> n && n != -1)
    {
        memset(g, false, sizeof(g));
        memset(reach, false, sizeof(reach)); //连通性
        for (int i = 1; i <= n; i++)
        {
            int k, door;
            cin >> energy[i] >> k;
            for (int j = 1; j <= k; j++)
            {
                cin >> door;
                g[i][door] = true;
                reach[i][door] = true;
            }
        }
        floyd();
        if (!reach[1][n])
        {
            cout << "hopeless" << endl;
            continue;
        }
        if (spfa(1))
            cout << "winnable" << endl;
        else
            cout << "hopeless" << endl;
    }
}
int main()
{
    solve();
    return 0;
}
