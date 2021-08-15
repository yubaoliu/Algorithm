// https://www.luogu.com.cn/problem/UVA536
#include <iostream>
using namespace std;

string preorder, inorder;
void postorder(string pre, string in)
{
    if (pre.size() <= 0)
        return;
    int len = 0;
    // while(in[len] !=pre[0])
    // {
    //     len++;
    // }
    len = in.find(pre[0]);
    postorder(pre.substr(1, len), in.substr(0, len));
    postorder(pre.substr(len + 1), in.substr(len + 1));
    cout<<pre[0];
}
// input 1: DBACEGF ABCDEFG
// output 1: ACBFGED
// input2: BCAD CBAD
// output2: CDAB
int main()
{
    while (cin >> preorder >> inorder)
    {
        postorder(preorder, inorder);
        cout << endl;
    }
    return 0;
}