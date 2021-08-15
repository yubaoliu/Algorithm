#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "common.h"

template <class T>
class Graph
{
private:
    int V;             // No. of vertices
    std::list<T> *adj; // Pointer to an array containing adjacency lists
    // std::vector<T> *adj;
public:
    Graph(int V);
    ~Graph();
    void BFS(T start);
    void DFS(T start);
    void addDirectedEdge(T v, T w);
    void addUndirectedEdge(T v, T w);
    void printGraph();
};

template <class T>
void Graph<T>::DFS(T start)
{
    std::stack<T> q;
    bool *visited = new bool[this->V];
    for (int i = 0; i < this->V; i++)
    {
        visited[i] = false;
    }
    q.push(start);
    while (!q.empty())
    {
        T f = q.top();
        q.pop();
        visited[f] = true;
        for (typename std::list<T>::iterator it = adj[f].begin(); it != adj[f].end(); it++)
        {
            if (!visited[*it])
            {
                q.push(*it);
                visited[*it] = true;
            }
        }
        std::cout << f << " ";
    }
    std::cout << std::endl;
}

template <class T>
void Graph<T>::BFS(T start)
{
    std::queue<T> q;
    bool *visited = new bool[this->V];
    for (int i = 0; i < this->V; i++)
    {
        visited[i] = false;
    }
    q.push(start);
    while (!q.empty())
    {
        T f = q.front();
        q.pop();
        visited[f] = true;
        for (typename std::list<T>::iterator it = adj[f].begin(); it != adj[f].end(); it++)
        {
            if (!visited[*it])
            {
                q.push(*it);
                visited[*it] = true;
            }
        }
        std::cout << f << " ";
    }
    std::cout << std::endl;
}

template <class T>
Graph<T>::Graph(int V)
{
    this->V = V;
    adj = new std::list<T>[V];
}

template <class T>
void Graph<T>::addDirectedEdge(T v, T w)
{
    // add w to v's list, directed graph
    adj[v].push_back(w);
}

template <class T>
void Graph<T>::addUndirectedEdge(T v, T w)
{
    // add w to v's list, directed graph
    adj[v].push_back(w);
    adj[w].push_back(v);
}

template <class T>
void Graph<T>::printGraph()
{
    std::cout << "\nAdjacency list of vertex. Total Num.:" << V << " \n";
    for (int v = 0; v < this->V; v++)
    {
        std::cout << v << ": ";
        for (typename std::list<T>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
        {
            T vertex = *it;
            std::cout << " -> " << vertex;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

template <class T>
Graph<T>::~Graph()
{
    for (int v = 0; v < this->V; v++)
    {
        typename std::list<T>::iterator it = adj[v].begin();
        while (it != adj[v].end())
        {
            it = adj[v].erase(it);
        }
    }
}

#endif