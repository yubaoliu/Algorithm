// https://vjudge.net/problem/POJ-3259
/* 
判正环/判负环:
1) BellFord
2) SPFA
3) DFS
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 505, maxe = 100001;
const int inf = 0x3f3f3f3f;
int T, n, m, w, cnt;
int head[maxn], dis[maxn], sum[maxn]; // dis: 距离; sum: 计数器,记录松弛的次数
bool vis[maxn];                       // 判断有没有被访问过
struct node
{
    int to, next, c;
} e[maxe];
void addedge(int u, int v, int cc)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].c = cc;
    head[u] = cnt;
}
// 用边来松弛,如果松弛超过n, 则说明有环
bool spfa(int u)
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    vis[u] = 1; // 标识是否在队列中
    dis[u] = 0;
    sum[u]++; // 记录每一个节点的入队次数
    q.push(u);
    // 停止: 1) 队列为空 2) 入队次数超过n
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0; // 已出队
        //访问x的所有邻接点
        for (int i = head[x]; i; i = e[i].next)
        {
            // 赿小赿更新
            if (dis[e[i].to] > dis[x] + e[i].c)
            {
                dis[e[i].to] = dis[x] + e[i].c;
                // 更新完之后,判断点是否在队列里,如果在队列里,什么也不做.
                if (!vis[e[i].to])
                {
                    // 判断入队次数有没有超过n
                    if (++sum[e[i].to] > n)
                        return false;    // 说明有负环
                    vis[e[i].to] = true; // 在队里
                    q.push(e[i].to);
                }
            }
        }
    }
    return true;
}
bool solve()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == inf)
        {
            if (!spfa(i))
                return true;
        }
    }
    return false;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cnt = 0;
        cin >> n >> m >> w; // n fields, m paths and w wormholes
        for (int i = 1; i <= n; i++)
        {
            head[i] = 0;
        }
        int u, v, t;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> t;
            addedge(u, v, t);
            addedge(v, u, t);
        }
        for (int i = 1; i <= w; i++)
        {
            cin >> u >> v >> t;
            addedge(u, v, -t);
        }
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}