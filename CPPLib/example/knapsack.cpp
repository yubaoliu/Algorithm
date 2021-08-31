#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// W: Total weights limination + 1
void knapsack(int w[], int v[], int n, int W, int **B)
{
    for (int k = 1; k < n; k++)
        for (int C = 1; C < W; C++)
        {
            if (w[k] > C)
            {
                B[k][C] = B[k - 1][C];
            }
            else
            {
                int value1 = B[k - 1][C - w[k]] + v[k];
                int value2 = B[k - 1][C];
                if (value1 > value2)
                {
                    B[k][C] = value1;
                }
                else
                {
                    B[k][C] = value2;
                }
            }
        }
}

int main()
{
    int w[6] = {0, 2, 3, 4, 5, 9};
    int v[6] = {0, 3, 4, 5, 8, 10};

    // int C[6][21];
    // for (int i = 0; i < 6; i++)
    //     for (int j = 0; j < 21; j++)
    //         B[i][j] = 0;
    int *B[6];

    for (int i = 0; i < 6; i++)
        B[i] = (int *)malloc(sizeof(int) * 21);

    knapsack(w, v, 6, 21, B);
    printf("%d\n", B[5][20]);
    return 0;
}