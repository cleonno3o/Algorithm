import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n = int(input())
    sticker = [list(map(int, input().split())) for _ in range(2)]
    dy = [[0] * n for _ in range(3)]
    dy[0][0] = sticker[0][0]
    dy[1][0] = sticker[1][0]
    for j in range(1, n):
        dy[0][j] = max(dy[1][j - 1] + sticker[0][j], dy[2][j - 1] + sticker[0][j])
        dy[1][j] = max(dy[0][j - 1] + sticker[1][j], dy[2][j - 1] + sticker[1][j])
        dy[2][j] = max(dy[0][j - 1], dy[1][j - 1])
    print(max(dy[0][n - 1], dy[1][n - 1], dy[2][n - 1]))