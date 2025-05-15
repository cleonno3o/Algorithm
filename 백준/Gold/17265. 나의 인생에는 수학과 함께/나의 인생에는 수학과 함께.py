import sys
input = sys.stdin.readline

max_res = -float('inf') 
min_res = float('inf')
drow = [0, 1]
dcol = [1, 0]

def dfs(r:int, c:int, val:int, op:str):
    global n, max_res, min_res
    if r == 0 and c == 0:
        val = board[r][c]
    elif '0' <= board[r][c] <= '5':
        val = eval(f"{val}{op}{board[r][c]}")
    else:
        op = board[r][c]
    if r == n - 1 and c == n - 1:
        if val > max_res: max_res = val
        if val < min_res: min_res = val
        return
    for i in range(2):
        n_row = r + drow[i]
        n_col = c + dcol[i]
        if n_row >= n or n_col >= n: continue
        dfs(n_row, n_col, val, op)

n = int(input().strip())
board = []
for _ in range(n):
    board.append(list(input().split()))
dfs(0,0,0,"")
print(max_res, min_res)