/*
https://www.youtube.com/watch?v=gpBHlWRAzh0&list=PLkNxDxyJqb-xD5EbDuIYC35Adq5f_w9CR&index=23
回溯法
*/
#include <iostream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 50;
int map[maxn][maxn], in[maxn], s[maxn]; // s: 标记出现
int ans[maxn];
string str, ord; // string, order
int len, num;
void dfs(int t) // 回溯法找所有的拓扑序
{
    if (t >= len) // 输出拓扑序
    {
        for (int i = 0; i < len; i++)
            cout << char(ans[i] + 'a');
        cout << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!in[i] && s[i]) //入度为0 且已出现
        {
            s[i]--;
            // 更新所有邻接点
            for (int j = 0; j < 26; j++)
                if (map[i][j])
                    in[j]--;
            ans[t] = i;
            dfs(t + 1);
            // 恢复现场
            for (int j = 0; j < 26; j++)
                if (map[i][j])
                    in[j]++;
            s[i]++;
        }
    }
}
int main()
{
    while (getline(cin, str))
    {
        memset(map, 0, sizeof(map));
        memset(in, 0, sizeof(in));
        memset(s, 0, sizeof(s));
        len = str.length();
        int i, j = 0;
        for (i = 0; i < len; i++)
        {
            if (str[i] != ' ')
            {
                s[str[i] - 'a']++;
                j++;
            }
        }
        len = j;           // j才是真正的长度
        getline(cin, ord); //读取秩序,成对出现
        num = ord.length();
        for (i = 0; i < num; i += 2)
        {
            int u = ord[i] - 'a';
            i += 2; // 中间有空隔
            int v = ord[i] - 'a';
            map[u][v] = 1;
            in[v]++;
        }
        dfs(0);
        cout << endl;
    }
    return 0;
}