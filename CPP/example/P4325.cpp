//https://www.luogu.com.cn/problem/P4325
// Given two integers A and B, A modulo B is the remainder when dividing A by B. For example, the numbers 7, 14, 27 and 38 become 1, 2, 0 and 2, modulo 3. Write a program that accepts 10 numbers as input and outputs the number of distinct numbers in the input, if the numbers are considered modulo 42.
/*input: 1
2
3
4
5
6
7
8
9
10
*/
// 使用筒排序
#include<bits/stdc++.h>

using namespace std;
bool a[42];
int main()
{
    int sum =0, x;
    memset(a, 0, sizeof(a));
    for(int i=0; i<10; i++)
    {
        cin >> x;
        a[x%42] = 1;
    }
    for(int i=0;i<42;i++)
    {
        if(a[i])
        {
            sum++;
        }
    }
    cout<<sum<<std::endl;
    return 0;
}

