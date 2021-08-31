// https://www.luogu.com.cn/problem/UVA514
/*
某城市有一个火车站，铁轨铺设如图。有n节车厢从A方向驶入车站，按进站的顺序编号为1～n。你的任务是判断是否能让他们按照某种特定的顺序进入B方向的铁轨并驶出车站。例如，出栈顺序（5 4 1 2 3）是不可能的，但（5 4 3 2 1）是可能的。 为了重组车厢，你可以借助中转站C。这是一个可以停放任意多节车厢的车站，但由于末端封顶，驶入C的车厢必须按照相反的顺序驶出C。对于每节车厢，一旦从A移入C，就不能返回A了;一旦从C移入B，就不能返回C了。也就是说，在任意时刻，只有两种选择：A到C和C到B。

对于每一组数据，第一行是一个整数 NN 。接下来若干行数据，每行 NN 个数，代表 11 ~ NN 车厢的出栈顺序，最后一组数据只有一个整数 00 。对于每一组数据，在最后输出空行。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxsize = 1000 + 5;
int n, B[maxsize];
int main()
{
    while (cin >> n && n)
    {
        while (1)
        {
            int i = 1, j = 1;
            cin >> B[1];
            if (!B[1])
                break;
            for (int i = 2; i <= n; i++)
                cin >> B[i];
            stack<int> s;
            while (i <= n)
            {
                if (i == B[j])
                {
                    i++;
                    j++;
                }
                else
                    s.push(i++);
                while (!s.empty() && s.top() == B[j])
                {
                    j++;
                    s.pop();
                }
            }
            if (j <= n)
                cout << "NO" << endl;
            else
                cout << "Yes" << endl;
        }
        cout << endl;
    }
    return 0;
}
