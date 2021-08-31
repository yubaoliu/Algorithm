/*
* Fibnacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
* Assume a(1)=1; a(2)=1; a(n+2)= a(n) + a(n+1)
* Please Calculate a(n)
* Algorithm:
* (a_n; a_n+1) = (0 1; 1 1)^(n-1) * (a_1 ; a_2)
*/
int fabonacci(int n)
{
    if (n <= 2)
        return 1;
    int current[2] = {1, 1};
    int next[2] = {0, 0};
    for (int i = 0; i < n - 1; i++)
    {
        next[0] = 0 * current[0] + 1 * current[1];
        next[1] = 1 * current[0] + 1 * current[1];
        current[0] = next[0];
        current[1] = next[1];
    }
    return current[0];
}

// dynamic programming
int dp_fabonacci(int n)
{
    int *fab = new int(n+3);
    for (int i = 0; i < n; i++)
        fab[i] = 0;
    fab[0] = 0;
    fab[1] = 1;
    fab[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        fab[i] = fab[i - 1] + fab[i - 2];
    }
    return fab[n];
}