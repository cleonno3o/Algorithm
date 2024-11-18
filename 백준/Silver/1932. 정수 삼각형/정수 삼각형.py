import sys
input = sys.stdin.readline
n = int(input())
tri = []
for i in range(n):
    tri.append(list(map(int, input().split())))
dy = [[0 for j in range(i + 1)] for i in range(n)]
dy[0] = tri[0]
for i in range(0, n - 1):
    for j in range(len(dy[i])):
        dy[i + 1][j] = max(dy[i + 1][j], dy[i][j] + tri[i + 1][j])
        dy[i + 1][j + 1] = max(dy[i + 1][j + 1], dy[i][j] + tri[i + 1][j + 1])
print(max(dy[n - 1]))