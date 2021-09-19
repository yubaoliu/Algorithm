// https://vjudge.net/problem/POJ-1797
// Heavy Transportation

#include <iostream>
#include <queue>
#include <math.h>
#include <cstring>
using namespace std;
const int maxn = 1005, maxe = 1000001;
const int inf = 0x3f3f3f3f; // 0x7fffffff
int senario, n, m, w, cnt;  //cnt: counter for edges
int head[maxn], dist[maxn]; //dist 经过顶点的最大承重量
bool vis[maxn];
struct node
{
    int to, w, next;
} e[maxe];

void addedge(int u, int v, int ww)
{
    //头插法
    e[++cnt].to = v;
    e[cnt].w = ww;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void printGraph(int n, int m)
{
    cout << "\n-------------\n";
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        j = head[i];
        while (j != -1)
        {
            cout << i << "->" << e[j].to << " ";
            j = e[j].next;
        }
        cout << endl;
    }
}
void dijkstra(int s)
{
    priority_queue<pair<int, int> > pqueue;
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    // for (int i = 1; i <= n; i++)
    // {
    //     vis[i] = false;
    //     dist[i] = 0; // 最大承重量
    // }
    // 求节点与边之间的最小值
    dist[s] = inf;
    // 最大值优先
    pqueue.push(make_pair(dist[s], s));
    while (!pqueue.empty())
    {
        // 堆顶
        int w = pqueue.top().first;
        int u = pqueue.top().second;
        pqueue.pop();
        // 已标记加入到最优解集合中
        if (vis[u])
            continue;
        vis[u] = true;
        // 已到达目标点
        if (vis[n])
            return;
        // find all the neighbors, 访问所有邻接点
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            int w = e[i].w;
            if (vis[v])
                continue;
            // int tmp = (w > dist[u]) ? dist[u] : w;
            // 更新最小重量的最大的那个
            if (dist[v] < min(dist[u], w))
            {
                dist[v] = min(dist[u], w);
                pqueue.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    int p = 1;
    cin >> senario;
    while (senario--)
    {
        cnt = 0;
        cin >> n >> m;
        // for (int i = 0; i <= n; i++)
        // {
        //     head[i] = -1;
        // }
        memset(head, -1, sizeof(head));
        for (int i = 0; i < m; i++)
        {
            int n1, n2;
            cin >> n1 >> n2 >> w;
            addedge(n1, n2, w);
            addedge(n2, n1, w);
        }
        dijkstra(1);
        cout << "Scenario #" << p++ << ":" << endl;
        cout << dist[n] << endl
             << endl;
    }

    // printGraph(n, m);
    // for (int i = 1; i <= n; i++)
    // {
    //     if(dist[i] == inf)
    //         cout<<"inf"<< " " ;
    //     else
    //         cout << dist[i] << " ";
    // }
    // cout << endl;

    return 0;
}