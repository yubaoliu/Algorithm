//https://vjudge.net/problem/POJ-1860
// Currency Exchange
//https://www.youtube.com/watch?v=UYd9ekZ0Eyc&list=PLkNxDxyJqb-xD5EbDuIYC35Adq5f_w9CR&index=20
/* 判正环:
 1) Bellman ford 算法, 用边松弛n-1次
 2) SPFA算法 (short path fast algorithm), 3259
 3) DFS
 */
#include <iostream>
#include <cstring>
using namespace std;
struct node
{
    int a, b;
    double r, c;
} e[210];
double dis[110];
int n, m, s, cnt = 0;
double v; // 最开始持有的金额
void add(int a, int b, double r, double c)
{
    //边集数组
    e[cnt].a = a;
    e[cnt].b = b;
    e[cnt].r = r;
    e[cnt++].c = c;
}
bool bellman_ford()
{
    memset(dis, 0, sizeof(dis));
    dis[s] = v;
    // n-1 次, 若没有cycle存在,任两个点的最短路径最多只经过n-1条边
    // 否则就会存在一个点被经过两次
    for (int i = 1; i < n; i++)
    {
        bool flag = 0; // 标识有没有松弛
        // cnt:边数, 边数是2m或cnt; 把每一条边都检查一次
        for (int j = 0; j < cnt; j++)
        {
            // 如有正环,会变大
            if (dis[e[j].b] < (dis[e[j].a] - e[j].c) * e[j].r)
            {
                dis[e[j].b] = (dis[e[j].a] - e[j].c) * e[j].r;
                flag = true;
            }
        }
        // 如果是求最短路径的话,这个地方break
        if (!flag)
            return false; // 没有更新,说明没有正环
    }
    // 再运行一次,如果仍然有更新,说明一定有正环
    for (int j = 0; j < cnt; j++)
    {
        if (dis[e[j].b] < (dis[e[j].a] - e[j].c) * e[j].r)
            return true;
    }
    return false;
}
int main()
{
    int a, b;
    double rab, cab, rba, cba;
    cin >> n >> m >> s >> v;
    while (m--)
    {
        cin >> a >> b >> rab >> cab >> rba >> cba;
        add(a, b, rab, cab);
        add(b, a, rba, cba);
    }
    if (bellman_ford())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
