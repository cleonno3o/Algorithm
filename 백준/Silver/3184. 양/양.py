import sys
from collections import deque

input = sys.stdin.readline

r, c = map(int, input().split())
board = []
check = [[False] * c for _ in range(r)]
wolf = sheep = 0
dRow = [-1, 0, 1, 0]
dCol = [0, 1, 0, -1]

def in_range(row, col):
    return 0 <= row < r and 0 <= col < c

def is_sheep_wolf(row, col, s, w):
    if board[row][col] == '.': pass
    elif board[row][col] == 'o': s += 1
    elif board[row][col] == 'v': w += 1
    return s, w

def bfs(row, col):
    global sheep, wolf
    q = deque()
    q.append((row, col))
    check[row][col] = True
    curr_sheep, curr_wolf = is_sheep_wolf(row, col, 0, 0)
    while len(q) != 0:
        row, col = q.popleft()
        for i in range(4):
            nRow = row + dRow[i]
            nCol = col + dCol[i]
            if in_range(nRow, nCol) and not check[nRow][nCol] and board[nRow][nCol] != '#':
                q.append((nRow, nCol))
                check[nRow][nCol] = True
                curr_sheep, curr_wolf = is_sheep_wolf(nRow, nCol, curr_sheep, curr_wolf)

    if curr_sheep > curr_wolf: wolf -= curr_wolf
    else: sheep -= curr_sheep

for i in range(r):
    row_str: str = input().rstrip()
    board.append(list(row_str))
    wolf += row_str.count('v')
    sheep += row_str.count('o')

for i in range(r):
    for j in range(c):
        if not check[i][j] and board[i][j] != '#':
            bfs(i, j)

print(sheep, wolf)