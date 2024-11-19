import sys

GARO = 0
SERO = 1
DIAG = 2
input = sys.stdin.readline
n = int(input())
board = [[0] * (n + 1)] + [[0] + list(map(int, input().split())) for _ in range(n)]
dy = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(3)]

dy[GARO][1][2] = 1
for i in range(3, n + 1):
    if board[1][i] == 0:
        dy[GARO][1][i] = dy[GARO][1][i - 1]

for i in range(2, n + 1):
    for j in range(2, n + 1):
        if board[i][j] == 1:
            continue
        dy[GARO][i][j] = dy[GARO][i][j - 1] + dy[DIAG][i][j - 1]
        dy[SERO][i][j] = dy[SERO][i - 1][j] + dy[DIAG][i - 1][j]
        if board[i - 1][j] == 0 and board[i][j - 1] == 0:
            dy[DIAG][i][j] = dy[GARO][i - 1][j - 1] + dy[SERO][i - 1][j - 1] + dy[DIAG][i - 1][j - 1]

print(dy[GARO][n][n] + dy[SERO][n][n] + dy[DIAG][n][n])
