// P1789 【Mc生存】插火把 https://www.luogu.com.cn/problem/P1789
#include <iostream>
using namespace std;
bool g[10000][10000];
int n, m, k;
int x, y;
// t=1: 火把；t=2: 荧石
void light(int x, int y, int t)
{
    for (int i = x - t; i <= x + t; i++) // 上下3/5层
        for (int j = y - t; j <= y + t; j++)
            if (i > n || i < 1 || j > n || j < 1)
                continue; // 超出范围
            else
                g[i][j] = 1;
}
void yingShi(int x, int y)
{
    light(x, y, 2);
}

void huoBa(int x, int y)
{
    light(x, y, 1);
    if (x + 2 <= n)
        g[x + 2][y] = 1;
    if (x - 2 > 0)
        g[x - 2][y] = 1;
    if (y + 2 <= n)
        g[x][y + 2] = 1;
    if (y - 2 > 0)
        g[x][y - 2] = 1;
}

int count()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] == 0)
                cnt++;
    return cnt;
}

int main()
{
    cin >> n >> m >> k; //m: huoba; k: yingshi
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        huoBa(x, y);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        yingShi(x, y);
    }
    cout << count();
    return 0;
}