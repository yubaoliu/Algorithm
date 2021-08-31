#include "dynamic_programming.h"

// 是否存在一个方案，使其和为S, arr={3, 34, 4, 12, 5, 2}
bool whetherSumIsS(int arr[], int n, int S)
{
    if (S == 0)
        return true;
    if (n == 0)
    {
        return (arr[0] == S);
        // if (arr[0] == S)
        //     return true;
        // else
        //     return false;
    }
    if (arr[n] > S)
    {
        return whetherSumIsS(arr, n - 1, S);
    }
    else
    {
        bool A = whetherSumIsS(arr, n - 1, S);
        bool B = whetherSumIsS(arr, n - 1, S - arr[n]);
        return (A || B);
    }
}

bool dp_whetherSumIsS(int arr[], int n, int S)
{
    if (S == 0)
        return true;
    bool opt[n + 1][S + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= S; j++)
            opt[i][j] = false;
    for (int i = 0; i <= S; i++)
    {
        if (arr[0] == opt[0][i])
        {
            opt[0][i] = true;
        }
        else
            opt[0][i] = false;
    }
    for (int i = 0; i <= n; i++)
    {
        opt[i][0] = true;
    }
    for (int i = 1; i <= n; i++)
        for (int s = 1; s <= S; s++)
        {
            if (arr[i] > s)
            {
                opt[i][s] = opt[i - 1][s];
            }
            else
            {
                bool A = opt[i - 1][s];
                bool B = opt[i - 1][s - arr[i]];
                opt[i][s] = A || B;
            }
        }
    return opt[n][S];
}