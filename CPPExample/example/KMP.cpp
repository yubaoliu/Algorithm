//https://www.youtube.com/watch?v=3IFxpozBs2I
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void prefix_table(char pattern[], int prefix[], int n)
{
    prefix[0] = 0;
    int len = 0; //公共前缀的下一项的位置
    int i = 1;   //遍历前缀表
    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
                len = prefix[len - 1];
            else
            {
                prefix[i] = len; //0
                i++;
            }
        }
    }
}

void move_prefix_table(int prefix[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

void kmp_search(char text[], char pattern[])
{
    int n = strlen(pattern);
    int m = strlen(text);
    int *prefix = (int *)malloc(sizeof(int) * n);
    prefix_table(pattern, prefix, n);
    move_prefix_table(prefix, n);
    int i = 0;
    int j = 0; 
    // text[i], len(text) = m
    // pattern[j], len(pattern) =n
    while (i < m)
    {
        if (j == n - 1 && text[i] == pattern[j])
        {
            printf("Found patter at %d\n", i - j);
            j = prefix[j];
        }
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = prefix[j];
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
}
int main()
{
    char pattern[] = "ABABCABAA";
    int prefix[9];
    int n = 9;
    prefix_table(pattern, prefix, n);
    move_prefix_table(prefix, 9);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", prefix[i]);
    }
    // char text[] = "ABABABCABAABABABAB";
    // kmp_search(text, pattern);
    return 0;
}