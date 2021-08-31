#include "graph.h"

using namespace std;

// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
void Graph::dijkstra(int **graph, int src, int V)
{
    int dist[V];    // dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        //Mark the picked vertex as processed
        sptSet[u] = true;
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int Graph::minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void Graph::BFS_shortest_path(std::list<int> *adj, int start, int end)
{
    int *parent = new int(this->V);
    BFS(adj, start, parent);
    stack<int> s;
    int v = end;
    while (-1 != v)
    {
        s.push(v);
        v = parent[v];
    }
    while (!s.empty())
    {
        std::cout << s.top();
        s.pop();
        if (s.size() > 0)
        {
            std::cout << "-";
        }
    }
    std::cout << std::endl;
}

void Graph::BFS(std::list<int> *adj, int start, int parent_out[])
{
    std::queue<int> q;
    bool *visited = new bool[this->V];
    for (int i = 0; i < this->V; i++)
    {
        visited[i] = false;
    }
    parent_out[start] = -1;
    q.push(start);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        visited[f] = true;
        for (typename std::list<int>::iterator it = adj[f].begin(); it != adj[f].end(); it++)
        {
            if (!visited[*it])
            {
                q.push(*it);
                visited[*it] = true;
                parent_out[*it] = f;
            }
        }
        std::cout << f << " ";
    }
    std::cout << std::endl;
}

void Graph::BFS(std::list<int> *adj, int start)
{
    std::queue<int> q;
    bool *visited = new bool[this->V];
    for (int i = 0; i < this->V; i++)
    {
        visited[i] = false;
    }
    q.push(start);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        visited[f] = true;
        for (typename std::list<int>::iterator it = adj[f].begin(); it != adj[f].end(); it++)
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

void Graph::DFS(std::list<int> *adj, int start)
{
    std::stack<int> q;
    bool *visited = new bool[this->V];
    for (int i = 0; i < this->V; i++)
    {
        visited[i] = false;
    }
    q.push(start);
    while (!q.empty())
    {
        int f = q.top();
        q.pop();
        visited[f] = true;
        for (std::list<int>::iterator it = adj[f].begin(); it != adj[f].end(); it++)
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

Graph::Graph(int V)
{
    this->V = V;
    // adj = new std::list<int>[V];
}

Graph::Graph(std::list<int> *adj, std::vector<Edge> &edges, int V)
{
    this->V = V;
    if (adj == nullptr)
        adj = new std::list<int>[this->V];
    for (std::vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
    {
        // std::cout<<(*it).src<<std::endl;
        adj[(*it).src].push_back((*it).dst);
    }
}

void Graph::addEdge(std::list<int> *adj, int src, int dst)
{
    // add w to v's list, directed graph
    adj[src].push_back(dst);
}

void Graph::addUndirectedEdge(std::list<int> *adj, int v, int w)
{
    // add w to v's list, directed graph
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printGraph(std::list<int> *adj)
{
    std::cout << "\nAdjacency list of vertex. Total Num.:" << V << " \n";
    for (int v = 0; v < this->V; v++)
    {
        std::cout << v << ": ";
        for (typename std::list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
        {
            int vertex = *it;
            std::cout << " -> " << vertex;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

Graph::~Graph()
{
    // for (int v = 0; v < this->V; v++)
    // {
    //     typename std::list<int>::iterator it = adj[v].begin();
    //     while (it != adj[v].end())
    //     {
    //         it = adj[v].erase(it);
    //     }
    // }
}