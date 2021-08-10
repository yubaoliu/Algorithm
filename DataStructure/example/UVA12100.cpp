// https://www.luogu.com.cn/problem/UVA12100
// UVA12100 打印队列 Printer Queue
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, n, m;
    cin >> T; // total task number
    for (int i = 0; i < T; i++)
    {
        queue<int> q;
        vector<int> a, b; // a: priority; b: sorted  priority
        int k = 0, x;
        cin >> n >> m; //n: nuber of jobs; m: my job number
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            a.push_back(x);
            b.push_back(x);
            q.push(j); // index of jobs
        }
        sort(b.begin(), b.end(), greater<int>()); // descent
        int w = 0;
        int max = 0;
        while (!q.empty())
        {
            max = b[w]; // the highest priority
            int t = q.front();
            if (a[t] < max)
            {
                q.pop();
                q.push(t);
            }
            else
            {
                if (t == m)
                {
                    cout << ++k << endl;
                    break;
                }
                else
                {
                    q.pop();
                    k++;
                    w++;
                }
            }
        }
    }
    return 0;
}