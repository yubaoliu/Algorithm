// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++)
    {
        int w = key[i];
        if (w < min && mstSet[i] == false)
        {
            min = w;
            min_index = i;
        }
    }
    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    for(int i=1; i<V; i++)
    {
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
}

// Function to construct and print MST for graph represented using adjacency matrix representation
void primMST(int graph[V][V])
{
    int parent[V];
    // Key values used to pick minimum weight edge in cut
    int key[V];
    bool mstSet[V]; // 标记是否在MST集合里
    // 初始化
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = INT_MAX;
        mstSet[i] = false;
    }
    //先把起始点放到关键路径里
    key[0] = 0; // 还没标记, 放到MST集合里
    parent[0] = -1;
    //再选出V-1个点
    for (int i = 0; i < V - 1; i++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && graph[u][v] < key[v] && mstSet[v] == false)
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
        mstSet[u] = true;
    }
    printMST(parent, graph);
}

// Driver code
int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9     */
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Print the solution
    primMST(graph);

    return 0;
}