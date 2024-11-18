import sys
input = sys.stdin.readline

n = int(input().rstrip())
dy = [[0] * 10 for i in range(n + 1)]
dy[1] = [0] + [1] * 9
for i in range(2, n + 1):
    for j in range(0, 10):
        if j == 0:
            dy[i][0] = dy[i - 1][1]
        elif j == 9:
            dy[i][9] = dy[i - 1][8]
        else:
            dy[i][j] = dy[i - 1][j - 1] + dy[i - 1][j + 1]
print(sum(dy[:][n]) % 1_000_000_000)