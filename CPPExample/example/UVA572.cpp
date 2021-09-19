// https://www.luogu.com.cn/problem/UVA572
/* UVA572 油田 Oil Deposits
输入多个m行n列的矩阵，用00表示输入结束。找出有多少块石油区域，用“@”代表石油，假如两个“@”在横，竖或对角线上相邻，就说它们位于同一区域，对于每个输入，输出一个数表示有几个石油区域。
*/
#include <iostream>
using namespace std;
const int maxn = 100 + 5;
string str[maxn];
int gid[maxn][maxn]; //连通分量号, -1表示没有分组
int ans[maxn];
int m, n;
// 行, 列, 连通分量号
void dfs(int r, int c, int id)
{
    // 越界检查
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;
    // 已有连通分量号或不是@
    if ((str[r][c] != '@') || (gid[r][c] >= 0))
        return;

    gid[r][c] = id;

    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
        {
            if ((dr == 0) && (dc == 0))
                continue;
            dfs(r + dr, c + dc, id);
        }
}

int main()
{
    int it = 0; // case数量

    while ((cin >> m >> n) && m && n)
    {
        int cnt = 0; // 连通分量计数

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                gid[i][j] = -1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            cin >> str[i];
        }
        // 遇到@符号,但没有编入组中的,判定为新的连通分量
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if ((str[i][j] == '@') && gid[i][j] == -1)
                    dfs(i, j, ++cnt);
            }
        // cout << cnt << endl;
        // 将每一轮的连通分量保存
        ans[it] = cnt;
        it++;
    }
    //输出结果
    for (int i = 0; i < it; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}