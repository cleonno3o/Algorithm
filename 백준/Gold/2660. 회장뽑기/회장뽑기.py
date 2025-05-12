import sys

input = sys.stdin.readline

n = int(input())
graph = [[2147000000] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    graph[i][i] = 0

while 1:
    s, e = map(int, input().split())
    if s == -1 and e == -1:
        break
    else:
        graph[s][e] = 1
        graph[e][s] = 1

for check_point in range(1, n + 1):
    for start in range(1, n + 1):
        for end in range(1, n + 1):
            graph[start][end] = min(graph[start][end], graph[start][check_point] + graph[check_point][end])

cand_score = 2147000000
cand = []
for start in range(1, n + 1):
    score = 0
    for end in range(1, n + 1):
        if graph[start][end] != 2147000000 and graph[start][end] > score:
            score = graph[start][end]
    if score < cand_score:
        cand_score = score
        cand = []
        cand.append(start)
    elif score == cand_score:
        cand.append(start)

print(cand_score, len(cand))
print(*cand)