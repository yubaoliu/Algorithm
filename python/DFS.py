graph = {
    "A": ["B", "C"],
    "B": ["A", "C", "D"],
    "C": ["A", "B", "D", "E"],
    "D": ["B", "C", "E", "F"],
    "E": ["C", "D"],
    "F": ["D"]
}

def DFS(graph, start):
    stack = []
    stack.append(start)
    seen = set()
    seen.add(start)
    while len(stack) > 0:
        vertex = stack.pop()
        nodes = graph[vertex]
        for w in nodes:
            if w not in seen:
                stack.append(w)
                seen.add(w)
        print(vertex)

print(graph.keys())
print(graph["E"])
DFS(graph, 'A')