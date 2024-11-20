import sys

input = sys.stdin.readline

n, m = map(int, input().split())
parent = [0] + list(map(int, input().split()))
child = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    if parent[i] != -1:
        child[parent[i]].append(i)

dy = [0] * (n + 1)
for i in range(m):
    target, w = map(int, input().split())
    dy[target] += w
for i in range(1, n + 1):
    for j in child[i]:
        dy[j] += dy[i]
print(*dy[1:])
