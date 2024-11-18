import sys
input = sys.stdin.readline
n = int(input().rstrip())
dy = [[0] * (n + 1) for _ in range(4)]
color = [[0] * (n + 1) for _ in range(4)]
for i in range(1, n + 1):
    color[1][i], color[2][i], color[3][i] = map(int, input().rstrip().split())
dy[1][1] = color[1][1]
dy[2][1] = color[2][1]
dy[3][1] = color[3][1]
for i in range(2, n + 1):
    for j in range(1, 3 + 1):
        target = [dy[1][i - 1], dy[2][i - 1], dy[3][i - 1]]
        target.pop(j - 1)
        dy[j][i] = min(target) + color[j][i]

print(min(dy[1][n],dy[2][n], dy[3][n]))