// https://www.luogu.com.cn/problem/UVA11988
// UVA11988 破损的键盘 Broken Keyboard (a.k.a. Beiju Text)
/*
你在输入文章的时候，键盘上的Home键和End键出了问题，会不定时的按下。你却不知道此问题，而是专心致志地打稿子，甚至显示器都没开。当你打开显示器之后，展现你面前的数一段悲剧文本。你的任务是在显示器打开前计算出这段悲剧的文本。 给你一段按键的文本，其中'['表示Home键，']'表示End键，输入结束标志是文件结束符（EOF）。
*/
#include <bits/stdc++.h>
using namespace std;
void solve(string s)
{
    int len = s.length();
    list<char> text;
    list<char>::iterator it = text.begin();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '[')
            it = text.begin();
        else if (s[i] == ']')
            it = text.end();
        else
        {
            it = text.insert(it, s[i]); // 在it之前插入
            it++; // 恢复it的位置
        }
    }
    for (it = text.begin(); it != text.end(); it++)
        cout << *it;
    s.clear();
    cout << endl;
}

int main()
{
    string s;
    while (cin >> s)
        solve(s);
    return 0;
}