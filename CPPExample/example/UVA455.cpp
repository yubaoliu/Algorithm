// UVA455 周期串 Periodic Strings
//https://www.luogu.com.cn/problem/UVA455
#include <bits/stdc++.h>
using namespace std;

int n, len, ans;
string s;
bool test(int T)
{
    for (int i = 0; i + T < len; i++)
    {
        if (s[i] != s[i + T])
            return false;
    }
    return true;
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s;
        len = s.length();
        ans = len;
        for (int T = 1; T < len; T++)
        {
            if (len % T == 0 && test(T))
            {
                ans = T;
                break;
            }
        }
        cout << ans << endl;
        if(n) 
            cout<<endl;
    }

    return 0;
}