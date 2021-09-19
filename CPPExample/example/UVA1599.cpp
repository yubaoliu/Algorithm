//https://ain-crad.github.io/2018/11/18/Uva1599-Ideal-Path/
/*
Input:
4 6
1 2 1
1 3 2
3 4 3
2 3 1
2 4 4
3 1 1
*/
#include <iostream>
#include <queue>
// #include <malloc.h>
// #include<stdlib.h>
using namespace std;
const int N = 100000 + 5, M = 200000 + 5, inf = 0x7fffffff;
int n, m, cnt;         // n个点,m 条边
int head[N];           // 存储边的下标
int dis[N];            // 保存距离
bool vis[N];           // 标记已遍历的节点
queue<int> q1, q2, q3; // q1: 节点; q2: 颜色; q3: 每一层中所有等于最小色号的结点
struct Edge
{
    int to, c, next;
} e[M];
void addedge(int u, int v, int c)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].c = c;
    e[cnt].next = head[u];
    // e[++cnt]=(Edge){v, c, head[u]};
    head[u] = cnt;
}
// 逆向标高求最短路径
void back_bfs(int nN)
{
    int u, v;
    for (int i = 0; i < nN + 1; i++)
    {
        vis[i] = 0;
    }
    dis[n] = 0;
    q1.push(n);
    vis[n] = true;
    while (!q1.empty())
    {
        u = q1.front();
        q1.pop();
        vis[u] = true;
        // 遍历所有邻接节点
        // cout<<u<<" ->"<<"\t";
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            v = e[i].to;
            if (vis[v])
                continue;
            dis[v] = dis[u] + 1;
            q1.push(v);
            vis[v] = true;
        }
    }
}
// 正向搜索
void bfs(int nN)
{
    int u, v, c, minc;
    bool first = true;
    for (int i = 0; i < nN + 1; i++)
    {
        vis[i] = 0;
    }
    vis[1] = true;
    // 1号节点的所有邻接点
    for (int i = head[1]; i != -1; i = e[i].next)
    {
        // 找到高度减1的邻接点, 入栈
        if (dis[e[i].to] == dis[1] - 1)
        {
            q1.push(e[i].to);
            q2.push(e[i].c);
        }
    }
    // 按节点展开, 循环Step 1 and Step 2
    while (!q1.empty())
    {
        minc = inf;
        // Step 1: 在邻接节点中找到颜色最小的边,并将对应的节点入栈到q3中
        while (!q1.empty())
        {
            v = q1.front();
            q1.pop();
            c = q2.front();
            q2.pop();
            // 如果发现更小的c, 则清空队列 q3
            if (c < minc)
            {
                while (!q3.empty())
                    q3.pop();
                minc = c;
            }
            if (c == minc)
            {
                q3.push(v);
            }
        } // q1
        if (first)
            first = false;
        else
            cout << " ";
        cout << minc;
        // Step 2: 处理颜色最小且相同的节点, 从q3继续展开
        while (!q3.empty())
        {
            u = q3.front();
            q3.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            // 找到路径减1的所有邻节点
            for (int i = head[u]; i != -1; i = e[i].next)
            {
                v = e[i].to;
                if (dis[v] == dis[u] - 1)
                {
                    q1.push(v);
                    q2.push(e[i].c);
                }
            }
        } // q3
    }     //q1
}
// void printGraph()
// {
//     int u = 1;
//     for (int i = head[u]; i != -1; i = e[i].next)
//     {
//         cout << e[i].to << " ";
//     }
//     cout << endl;
// }
int main()
{
    int u, v, c;
    // cin >> n >> m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n + 1; i++)
        {
            head[i] = -1;
            dis[i] = inf;
        }
        for (int i = 0; i < m + 1; i++)
        {
            e[i].c = -1;
            e[i].to = -1;
            e[i].next = -1;
        }
        cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> c;
            // 无向图,有重边
            addedge(u, v, c);
            addedge(v, u, c);
        }
        // cout << endl;
        back_bfs(n);
        cout << dis[1] << endl;
        bfs(n);
        // show the distance
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << dis[i] << "\t";
        // }
        cout << endl;
        // printGraph();
    }

    return 0;
}