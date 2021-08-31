#include "../include/graph.h"

using namespace std;

int main()
{
    // TEST 1
    Graph graph(5);

    std::list<int> *adj = new std::list<int>[5];

    graph.addUndirectedEdge(adj, 0, 1);
    graph.addUndirectedEdge(adj, 0, 4);
    graph.addUndirectedEdge(adj, 1, 2);
    graph.addUndirectedEdge(adj, 1, 3);
    graph.addUndirectedEdge(adj, 1, 4);
    graph.addUndirectedEdge(adj, 2, 3);
    graph.addUndirectedEdge(adj, 3, 4);

    graph.printGraph(adj);

    std::cout << "-----BFS-----" << std::endl;
    graph.BFS(adj, 0);

    std::cout << "-----DFS-----" << std::endl;
    graph.DFS(adj, 0);

    std::cout << "-----Shortest path: 0-3-----" << std::endl;
    graph.BFS_shortest_path(adj, 0, 3);

    // TEST 2
    std::cout << "==================================" << std::endl;
    // directed edge
    vector<Edge> edges =
        {{0, 1, 1}, {1, 2, 1}, {2, 0, 1}, {2, 1, 1}, {3, 2, 1}, {4, 5, 1}, {5, 4, 1}};

    std::list<int> *adj2 = new std::list<int>[8];
    Graph *graph2 = new Graph(adj2, edges, 8);

    std::cout << "-----DFS2-----" << std::endl;
    graph2->DFS(adj2, 0);

    cout << "----END----" << std::endl;
    return 0;
}