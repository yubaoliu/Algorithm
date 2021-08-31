#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "common.h"

struct Edge
{
    int src;
    int dst;
    int weight;
    Edge(int src, int dst, int weight)
    {
        this->src = src;
        this->dst = dst;
        this->weight = weight;
    }
};

class Graph
{
private:
    int V; // No. of vertices
           // std::list<int> *adj; // Pointer to an array containing adjacency lists
           // std::vector<int> *adj;
           // int **graph; // graph[][], adjacency matrix representation
    int minDistance(int dist[], bool sptSet[], int V);

public:
    Graph(int V);                                                // link list
    Graph(std::list<int> *adj, std::vector<Edge> &edges, int V); // link list
    ~Graph();
    void BFS(std::list<int> *adj, int start, int parent_out[]);
    void BFS(std::list<int> *adj, int start);
    void DFS(std::list<int> *adj, int start);
    void BFS_shortest_path(std::list<int> *adj, int start, int end);
    void addEdge(std::list<int> *adj, int src, int dst);
    void addUndirectedEdge(std::list<int> *adj, int v, int w);
    void printGraph(std::list<int> *adj);
    void dijkstra(int **graph, int src, int V);
};

#endif