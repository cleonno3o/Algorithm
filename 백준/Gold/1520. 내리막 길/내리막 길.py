import heapq

drow = [1, 0, -1, 0]
dcol = [0, 1, 0, -1]

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
ch = [[0] * m for _ in range(n)]
ch[0][0] = 1
pq = []
heapq.heappush(pq, (-board[0][0], 0, 0))
while len(pq) > 0:
    h, r, c = heapq.heappop(pq)
    for i in range(4):
        nRow = r + drow[i]
        nCol = c + dcol[i]
        if 0 <= nRow < n and 0 <= nCol < m and board[nRow][nCol] < board[r][c]:
            if ch[nRow][nCol] == 0:
                heapq.heappush(pq, (-board[nRow][nCol], nRow, nCol))
            ch[nRow][nCol] += ch[r][c]
print(ch[n - 1][m - 1])