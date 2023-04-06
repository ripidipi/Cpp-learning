from  random import randint


def addEdge():
    if u > v:
        u, v = v, u
    if (u, v) in edges:
        return False
    edges.add((u, v))
    return True

n, m =[int(i)for i in input().split()]
edges  = set()
for i in range(1, n):
    p = randint(0, n-1)
    addEdge(adges, p, i)
m-=(n-1)
while m>0:
    while True:
        u = randint(0, n-1)
        v = randint(0, n-1)
        while u == v:
            v = randint(0, n-1)
            if addEdge(edges, u, v):
                break
for e in edges:
    print (*e)
