import sys
import heapq

input = sys.stdin.readline
drow = [-1, 0, 1, 0]
dcol = [0, 1, 0, -1]

m, n = map(int, input().strip().split())
board = [[-1] for _ in range(n + 1)]
record = [[2147000000] * (m + 1) for __ in range(n + 1)]
for i in range(1, n + 1):
    for num in input().strip():
        board[i].append(int(num))

pq = []
heapq.heappush(pq, (0, 1, 1))
while len(pq) != 0:
    broken, row, col = heapq.heappop(pq)
    if row == n and col == m:
        print(broken)
        break
    else:
        for dr, dc in zip(drow, dcol):
            n_row = row + dr
            n_col = col + dc
            if n_row > n or n_row < 1 or n_col > m or n_col < 1: continue
            if n_row == 1 and n_col == 1: continue
            if record[n_row][n_col] > broken + board[n_row][n_col]:
                record[n_row][n_col] = broken + board[n_row][n_col]
                heapq.heappush(pq, (broken + board[n_row][n_col], n_row, n_col))