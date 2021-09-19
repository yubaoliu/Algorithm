#include <iostream>
#include <stdio.h>
using namespace std;
const int MaxN = 1000000 + 5;
int prefixTable[MaxN]; //patternLen + 1
int sLen;
int patternLen;

void get_next(string pattern)
{
    int j = 0;  // 遍历pattern串
    int k = -1; // 最长公共前后缀
    prefixTable[0] = -1;
    while (j < patternLen)
    {
        if (k == -1)
        {
            prefixTable[++j] = ++k;
            continue;
        }
        if (pattern[k] == pattern[j])
        {
            prefixTable[++j] = ++k;
        }
        else
        {
            // 如果找不到,向前回退
            k = prefixTable[k];
        }
    }
}
void KMP(string s, string pattern)
{
    int i = 0, j = 0;
    sLen = s.length();
    patternLen = pattern.length();
    get_next(pattern);
    while (i < sLen)
    {
        if (j == -1 || s[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = prefixTable[j];
        }
        if (j == patternLen) // match succeed
        {
            cout << i - patternLen + 1 << endl;
            j = prefixTable[j];
        }
    }
}

int main()
{
    // Test prefix table
    // string pattern = "ABA"; //ABABCABAA
    // patternLen = pattern.length();
    // int n = 3;
    // get_next(pattern);
    // for (int i = 0; i <= n; i++)
    // {
    //     printf("%d\n", prefixTable[i]);
    // }

    string s, t;
    while (cin >> s >> t)
    {
        KMP(s, t);
        for (int i = 1; i <= patternLen; i++)
        {
            cout << prefixTable[i] << " ";
        }
        cout << endl;
    }
    return 0;
}