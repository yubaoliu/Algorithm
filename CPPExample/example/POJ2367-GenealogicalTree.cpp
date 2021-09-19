//https://www.youtube.com/watch?v=pk56_z6xZxE&list=PLkNxDxyJqb-xD5EbDuIYC35Adq5f_w9CR&index=22
// 拓扑排序
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 105;
int map[maxn][maxn], indegree[maxn], topo[maxn];
int n;
stack<int> s;
void TopoSort()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            s.push(i);
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        topo[++cnt] = u;
        // 更新u的所有临接点
        for (int j = 1; j <= n; j++)
            if (map[u][j])
            {
                if (--indegree[j] == 0)
                    s.push(j);
            }
    }
}
int main()
{
    cin >> n;
    memset(map, 0, sizeof(map));
    memset(indegree, 0, sizeof(indegree));
    for (int i = 1; i <= n; i++)
    {
        int v;
        while (cin >> v && v)
        {
            map[i][v] = 1;
            indegree[v]++;
        }
    }
    TopoSort();
    for (int i = 1; i < n; i++)
        cout << topo[i] << " ";
    cout << topo[n] << endl;
    return 0;
}
