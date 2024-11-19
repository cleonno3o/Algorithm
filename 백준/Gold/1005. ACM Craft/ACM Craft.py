import sys
from collections import deque

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    time = [0] + list(map(int, input().split()))
    build = [[] for _ in range(n + 1)]
    inDegree = [0] * (n + 1)
    dy = [0] * (n + 1)
    for i in range(k):
        s, e = map(int, input().split())
        build[s].append(e)
        inDegree[e] += 1
    target = int(input())
    q = deque()
    for i in range(1, n + 1):
        if inDegree[i] == 0:
            q.append(i)
            dy[i] = time[i]

    while len(q) != 0:
        s = q.popleft()
        for e in build[s]:
            inDegree[e] -= 1
            dy[e] = max(dy[e], dy[s] + time[e])
            if inDegree[e] == 0:
                q.append(e)
    print(dy[target])
