// https://www.luogu.com.cn/problem/P1151
/*
现在给定一个正整数KK，要求你编程求出1000010000到3000030000之间所有满足下述条件的五位数，条件是这些五位数的三个子数sub_1,sub_2,sub_3 都可被KK整除。
sub 1=a1a2​a3
sub_2=a_2a_3a_4
sub_3=a_3a_4a_5
 */
#include<iostream>
using namespace std;
int main()
{
    int k, s1, s2, s3;
    bool flag = 0;
    cin>>k;
    for(int i=10000; i<=30000; i++)
    {
        s1=i/100;
        s2=(i/10)%1000;
        s3=i%1000;
        if(s1%k==0 && s2%k==0 && s3%k==0)
        {
            flag = 1;
            cout<<i<<endl;
        }
    }
    if(!flag)
        cout<<"No"<<endl;
    return 0;
}
