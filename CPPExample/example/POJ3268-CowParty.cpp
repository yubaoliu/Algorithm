// https://vjudge.net/problem/POJ-3268
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 10005, maxe = 100005;
const int inf = 0x3f3f3f3f;
int n, m, x, cnt, rcnt;
int head[maxn], rhead[maxn], dis[maxn], rdis[maxn];
bool vis[maxn];
// 建立两个图,一个正向图,一个反向图
struct node
{
    int to, next, c;
} fe[maxe], re[maxe];
void add(node *e, int *head, int u, int v, int cc, int &cnt)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].c = cc;
    head[u] = cnt;
}
void spfa(node *e, int *head, int u, int *dis)
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, maxn * sizeof(int));
    // memset(dis, 0x3f, (n + 1) * sizeof(int)); // 按字节填充
    // fill(dis + 1, dis + n + 1, inf); //按数组单元填充
    // for (int i = 1; i <= n; i++)
    // {
    //     dis[i] = inf;
    // }
    vis[u] = 1;
    dis[u] = 0;
    q.push(u);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = e[i].next)
        {
            if (dis[e[i].to] > dis[x] + e[i].c)
            {
                dis[e[i].to] = dis[x] + e[i].c;
                if (!vis[e[i].to])
                {
                    vis[e[i].to] = 1;
                    q.push(e[i].to);
                }
            }
        }
    }
}
void printg(node *e, int *head)
{
    cout << "---------" << endl;
    for (int u = 1; u <= n; u++)
    {
        cout << u << "\t";
        for (int i = head[u]; i; i = e[i].next)
        {
            cout << e[i].to << " " << e[i].c << "\t\t";
        }
        cout << endl;
    }
}
void print(int *dis)
{
    cout << "--------------" << endl;
    for (int i = 1; i <= n; i++)
        cout << dis[i] << endl;
}
int main()
{
    cin >> n >> m >> x; // N farms, M: unidirectional road; x: 聚会场所
    cnt = rcnt = 0;
    memset(head, 0, sizeof(head));
    memset(rhead, 0, sizeof(rhead));
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(fe, head, u, v, w, cnt);
        // 建立一个反向图
        add(re, rhead, v, u, w, rcnt);
    }
    // printg(fe, head);
    // printg(re, rhead);
    spfa(fe, head, x, dis);
    // print(dis);
    spfa(re, rhead, x, rdis);
    // print(dis);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, (long long)dis[i] + rdis[i]);
    cout << ans << endl;
    return 0;
}