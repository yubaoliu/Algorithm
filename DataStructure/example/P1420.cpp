// P1420 最长连号, https://www.luogu.com.cn/problem/P1420
#include <iostream>
using namespace std;
int a[1000 + 5];
int main()
{
    int n, cnt = 1, max = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i + 1] == a[i] + 1)
        {
            cnt++;
            if (max < cnt)
                max = cnt;
        }
        else
        {
            cnt = 1;
        }
    }
    cout<<max;
    return 0;
}
