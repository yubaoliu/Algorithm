//https://www.luogu.com.cn/problem/P2956
#include <iostream>
#include<cstring>
using namespace std;
bool a[240 + 5][240 + 5];
void func(int x, int y, int s, int t)
{
    for (int i = x; i <= s; i++)
        for (int j = y; j <= t; j++)
            a[i][j] = 1;
}
int main()
{
    int m, n, c; // m: rows; n: cols; c: number of commands
    int x, y;    // coordinate of the start point
    int s, t;    // end point
    int count = 0;
    cin >> m >> n >> c;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < c; i++)
    {
        cin >> x >> y >> s >> t;
        func(x, y, s, t);
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
                count++;
        }
    cout << count;
    return 0;
}