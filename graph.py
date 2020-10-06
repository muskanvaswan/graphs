class Vertice():
    def __init__(self, data, id):
        self.id = id
        self.data = data
        self.incoming = []
        self.outgoing = []

    def incomingEdge(self, frm):
        if frm not in self.incoming:
            self.incoming.append(frm)

    def outgoingEdge(self, to):
        if to not in self.outgoing:
            self.outgoing.append(to)

    def __str__(self):
        return f"{self.id}: {self.data}"

class Graph():

    def __init__(self, n):
        self.vertices = []
        self.limit =  n
        self.edges = []
        self.current = 0

    def addVertice(self, data):
        id = self.current
        vertice = Vertice(data, id)
        self.vertices.append(vertice)
        self.current += 1

        return id

    def makeEdge(self, frm, to):

        x = self.vertices[frm]
        y = self.vertices[to]

        y.incomingEdge(x)
        x.outgoingEdge(y)

        edge = (to, frm)
        self.edges.append(edge)
