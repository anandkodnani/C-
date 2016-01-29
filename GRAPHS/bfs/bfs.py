import Queue
class Graph:
    def __init__(self, vertices) :
        self.V = vertices
        self.adj = {}
        self.nodes = []
        self.visited = {}
        
    def addVertex(self, vertex) :
        self.nodes.append(vertex)
        self.visited[vertex] = False
        self.adj[vertex] = []

    def addEdge(self, u, v) :
        if u not in self.nodes :
            self.addVertex(u)
        if v not in self.nodes :
            self.addVertex(v)
        self.adj[u].append(v)

    def printNodes(self) :
        print "\nNodes are\n"
        for i in self.nodes :
            print i

    def bfs(self, start) :        
        q = Queue.Queue()
        q.put(start)
        self.visited[start] = True

        while not q.empty() :
            v = q.get()
            print v, " "
            for x in self.adj[v] :
                if self.visited[x] is False :
                    q.put(x)
                    self.visited[x] =  True
        

g = Graph(4)
g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 2);
g.addEdge(2, 0);
g.addEdge(2, 3);
g.addEdge(3, 3);

g.printNodes()
g.bfs(2)
    
