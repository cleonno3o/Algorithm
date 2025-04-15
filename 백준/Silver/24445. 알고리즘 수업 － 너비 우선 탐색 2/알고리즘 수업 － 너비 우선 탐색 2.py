import sys
from collections import deque
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = [[] for _ in range(n + 1)]
visit = [0] * (n + 1)

for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

cost = 1
q = deque()
q.append(r)
visit[r] = cost
for node in graph:
    node.sort(reverse=True)
    
while len(q) != 0:
    s = q.popleft()
    for node in graph[s]:
        if visit[node] == 0:
            cost += 1
            visit[node] = cost
            q.append(node)

for i in range(1, n + 1):
    print(visit[i])