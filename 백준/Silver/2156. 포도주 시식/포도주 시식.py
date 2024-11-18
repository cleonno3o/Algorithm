import sys
input = sys.stdin.readline
n = int(input())
wine = []
for i in range(n):
    wine.append(int(input()))
dy = [[0] * n for i in range(3)]
dy[1][0] = wine[0]
for i in range(1, n):
    # 내가 고른다
    dy[1][i] = dy[0][i - 1] + wine[i]
    dy[2][i] = dy[1][i - 1] + wine[i]
    # 안고른다
    dy[0][i] = max(dy[0][i - 1], dy[1][i - 1], dy[2][i - 1])
print(max(dy[0][n - 1], dy[1][n - 1], dy[2][n - 1]))