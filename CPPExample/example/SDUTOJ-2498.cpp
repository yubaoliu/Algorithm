/*
https://acm.sdut.edu.cn/onlinejudge3/problems/2498

最长路径
输出字典序最小的路径

解决方法:
- Dijkstra O(n^2), 不能处理负权边
- Bellman  O(nm)
- SPFA O(km) 
- 按拓扑序 

松弛条件:
1) 赿长赿好
2) 路径长度相等,字典序小,更新前驱
建反向图

解题思路:
1) 建立原图的逆向图,检查入度为0的点s和出度为0的点t, 实际上, 一个工程项目只有一个s和t
2) 使用SPFA算法求最长路径,如果
dist[y] < dist[x] + e[i] || (dist[y] == dist[x] + e[i] && x < pre[y])
更新
dist[y] = dist[x] + e[i].w
pre[y] = x
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 10010, maxe = 50010;
int n, m, cnt;
int head[maxn], dis[maxn]; // 链式前向星
int pre[maxn], in[maxn], out[maxn];
bool inq[maxn];
struct node
{
    int to, next, w;
} e[maxe];
void add(int u, int v, int w)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
    e[cnt].w = w;
}
void spfa(int u)
{
    queue<int> q;
    q.push(u);
    inq[u] = 1; //标记节点在队列之中
    while (!q.empty())
    {
        int x = q.front(); //取队头
        q.pop();
        inq[x] = 0;
        //访问所有邻接点
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y] < dis[x] + e[i].w || (dis[y] == dis[x] + e[i].w && x < pre[y]))
            {
                dis[y] = dis[x] + e[i].w;
                pre[y] = x;
                if (!inq[y])
                {
                    q.push(y);
                    inq[y] = 1;
                }
            }
        }
    }
}
int main()
{
    int u, v, w, s, t;
    while (cin >> n >> m)
    {
        memset(head, 0, sizeof(head));
        memset(dis, 0, sizeof(dis));
        memset(inq, 0, sizeof(inq));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(pre, -1, sizeof(pre));
        cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            add(v, u, w);
            out[v]++;
            in[u]++;
        }
        // 判断源点与汇点
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
                s = i;
            if (out[i] == 0)
                t = i;
        }
        spfa(s);
        cout << dis[t] << endl;
        int k = t;
        while (pre[k] != -1)
        {
            cout << k << " " << pre[k] << endl;
            k = pre[k];
        }
    }
    return 0;
}