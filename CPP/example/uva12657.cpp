//https://www.luogu.com.cn/problem/UVA12657
/*
你有n个盒子在桌子上的一条线上从左到右编号为1……n。你的任务是模拟四种操作

1 X Y 移动盒子编号X到盒子编号Y的左边（如果X已经在Y的左边了就忽略）

2 X Y 移动盒子编号X到盒子编号Y的右边（如果X已经在Y的右边了就忽略）

3 X Y 交换盒子编号X与盒子编号Y的位置

4 将整条线反转

操作保证合法，X不等于Y

举一个例子，如果n=6，操作 1 1 4然后就变成了2 3 1 4 5 6；再操作 2 3 5就变成了 2 1 4 5 3 6；再操作 3 1 6 就变成 2 6 4 5 3 1；最后操作4，就变成了 1 3 5 4 6 2

输入

最多有10组数据，每个数据会包含两个整数n,m（1≤n,m<100,000）, 接下来是m行数据，表示操作。

输出

对于每组数据，输出他们奇数位置的编号的和。
*/
#include <bits/stdc++.h>
using namespace std;

int r[100000 + 5], l[100000 + 5];
// 建立双向静态链表
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        l[i] = i - 1;
        r[i] = (i + 1) % (n + 1);
    }
    r[0] = 1;
    l[0] = n;
}
void link(int L, int R)
{
    l[R] = L;
    r[L] = R;
}
int main()
{
    int n, m, a, x, y, k = 0;
    bool flag;
    // k: case number
    while (cin >> n >> m)
    {
        flag = false;
        // n: 盒子的个数
        init(n);
        //m: number of commands
        for (int i = 0; i < m; i++)
        {
            cin >> a; // 命令编号
            if (a == 4) //翻转
            {
                flag = !flag;
            }
            else
            {
                cin >> x >> y;
                if (a == 3 && r[y] == x) // y 的后继是 x
                    swap(x, y);
                if (a != 3 && flag)
                    a = 3 - a;
                if (a == 1 && x == l[y]) 
                    continue;
                if (a == 2 && x == r[y])
                    continue;
                int Lx = l[x], Rx = r[x], Ly = l[y], Ry = r[y];
                if (a == 1) // x插入到y的左边, move to left
                {
                    link(Lx, Rx); // delete x
                    link(Ly, x);
                    link(x, y);
                }
                else if (a == 2) // move x to right of y
                {
                    link(Lx, Rx);
                    link(y, x);
                    link(x, Ry);
                }
                else if (a == 3) // swap x and y
                {
                    if (r[x] == y)
                    {
                        link(Lx, y);
                        link(y, x);
                        link(x, Ry);
                    }
                    else
                    {
                        link(Lx, y);
                        link(y, Rx);
                        link(Ly, x);
                        link(x, Ry);
                    }
                }
            }
        }
        std::cout<< std::flush;
        int t = 0;
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            t = r[t];
            if (i % 2 == 1)
                sum += t;
        }
        if (flag && n % 2 == 0)
            sum = (long long)n * (n + 1) / 2 - sum;
        cout << "Case " << ++k << ": " << sum << endl;
    }
    return 0;
}