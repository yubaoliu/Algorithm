graph = {
    "A": ["B", "C"],
    "B": ["A", "C", "D"],
    "C": ["A", "B", "D", "E"],
    "D": ["B", "C", "E", "F"],
    "E": ["C", "D"],
    "F": ["D"]
}


def BFS(graph, start):
    queue = []
    queue.append(start)
    seen = set()
    seen.add(start)
    parent = {start: None}
    while len(queue) > 0:
        vertex = queue.pop(0)
        nodes = graph[vertex]
        for c in nodes:
            if c not in seen:
                queue.append(c)
                seen.add(c)
                parent[c] = vertex
        # print(vertex)
    return parent


def shortest_path(graph, start, end):
    parent = BFS(graph, start)
    stack = []
    while end != None:
        # print(end)
        stack.append(end)
        end = parent[end]
    # show path
    while len(stack) > 0:
        v = stack.pop()
        print(v)

#print(graph.keys())
#print(graph["E"])
#parent = BFS(graph, 'A')

#print("------------Show parent array------")
#for key in parent:
#    print(key, ":", parent[key])

print("----shortest path--------")
shortest_path(graph, "B", "E")