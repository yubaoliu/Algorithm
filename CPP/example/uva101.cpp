// https://www.luogu.com.cn/problem/UVA101
/*
初始时从左到右有 nn 个木块，编号为 0 \ldots n-10…n−1,要求实现下列四种操作：

move a onto b : 把 aa 和 bb 上方的木块归位，然后把 aa 放到 bb 上面。
move a over b : 把 aa 上方的木块归位，然后把 aa 放在 bb 所在木块堆的最上方。
pile a onto b : 把 bb 上方的木块归位，然后把 aa 及以上的木块坨到 bb 上面。
pile a over b : 把 aa 及以上的木块坨到 bb 的上面。
一组数据的结束标志为 quit，如果有非法指令（如 aa 与 bb 在同一堆），无需处理。
输出:所有操作输入完毕后，从左到右，从下到上输出每个位置的木块编号。
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> block[30];
void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        block[i].push_back(i);
    }
}

void loc(int x, int &p, int &h) //h: height; p: pos
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < block[i].size(); j++)
        {
            if (block[i][j] == x)
            {
                p = i;
                h = j;
            }
        }
}

void goback(int p, int h)
{
    for (int i = h + 1; i < block[p].size(); i++)
    {
        int k = block[p][i];
        block[k].push_back(k);
    }
    block[p].resize(h + 1);
}

void moveall(int p, int h, int q) // p 位>=h之上的所有块移到到q之上
{
    for (int i = h; i < block[p].size(); i++)
    {
        int k = block[p][i];
        block[q].push_back(k);
    }
    block[p].resize(h);
}

void solve()
{
    int a, b;
    string s1, s2;
    while (cin >> s1)
    {
        if (s1 == "quit")
            break;
        cin >> a >> s2 >> b;
        int ap = 0, ah = 0, bp = 0, bh = 0;
        loc(a, ap, ah);
        loc(b, bp, bh);
        if (ap == bp)
            continue;
        if (s1 == "move") // a 归位
            goback(ap, ah);
        if (s2 == "onto") //b归位
            goback(bp, bh);
        moveall(ap, ah, bp);
    }
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int j = 0; j < block[i].size(); j++)
        {
            cout << " " << block[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    init();
    solve();
    print();
    return 0;
}