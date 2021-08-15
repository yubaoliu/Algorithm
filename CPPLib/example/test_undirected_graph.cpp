#include "../include/graph.h"

using namespace std;

int main()
{
    Graph<int> graph(5);

    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 4);
    graph.addUndirectedEdge(1, 2);
    graph.addUndirectedEdge(1, 3);
    graph.addUndirectedEdge(1, 4);
    graph.addUndirectedEdge(2, 3);
    graph.addUndirectedEdge(3, 4);

    graph.printGraph();

    std::cout << "-----BFS-----" << std::endl;
    graph.BFS(0);


    std::cout << "-----DFS-----" << std::endl;
    graph.DFS(0);

    cout << "----END----" << std::endl;
    return 0;
}